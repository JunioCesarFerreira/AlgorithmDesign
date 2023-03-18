#include <conio.h>
#include <stdio.h>

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

typedef struct
{
    int id;
    int* preferences;
    bool free;
    int fiance;
} anybody;

bool thereIsFreeMan(anybody* men, int* m, int size)
{
    bool result = false;
    for (int i=0; i<size; i++)
    {
        if (men[i].free)
        {
            *m = i;
            result = true;
            break;
        }
    }
    return result;
}

bool prefersThis(int suitor, anybody* intended, int size)
{
    int preference_suitor = -1;
    int preference_actual = -1;
    for (int i=0; i<size; i++)
    {
        if (intended->preferences[i]==suitor)
        {
            preference_suitor = i;
        }
        if (intended->preferences[i]==intended->fiance)
        {
            preference_actual = i;
        }
    }
    return preference_suitor < preference_actual;
}

void engagement (anybody* man, anybody* woman)
{
    man->fiance = woman->id;
    woman->fiance = man->id;
    man->free = false;
    woman->free = false;
    printf("engagement %d %d\n", man->id, woman->id);
}

void searchForWeddings(int length, anybody* men, anybody* women)
{
    int m;
    while (thereIsFreeMan(men, &m, length))
    {
        printf("scope man: %d\n", m);
        for (int i=0; i<length; i++)
        {
            int w = men[m].preferences[i];
            if (women[w].free)
            {
                engagement(&men[m], &women[w]);
                break;
            }
            else
            {
                if (prefersThis(m, &women[w], length))
                {
                    men[women[w].fiance].free = true;
                    men[women[w].fiance].fiance = -1;
                    engagement(&men[m], &women[w]);
                    break;
                }
            }
        }
    }
}

void parse_preferences(string line, int *preferences)
{     
    char separator = ' ';
    int i = 0;    
    int pref_index = 0;
    string s; 
    bool first = true;
    while (line[i] != '\0') 
    {
        if (line[i] != separator) s += line[i]; 
        else 
        {
            if (first)
            {
                first = false;
                s.clear();
            } 
            else
            {
                preferences[pref_index] = stoi(s) - 1;
                pref_index++;
                s.clear();
            }
        }
        i++;
    }
    if (s.length()>0) preferences[pref_index] = stoi(s) - 1;
}


int main(int argc, char **argv) 
{
    ifstream file;
    file.open("Test.txt");
    string line;
    string input;
    string output;
    if (file.is_open()) 
    {
        getline (file, line);
        input += line + "\n";
        int amount_test = stoi(line);
        for (int test=0; test<amount_test; test++)
        {
            getline (file, line);
            input += line + "\n";
            int test_length = stoi(line);
            anybody* men = new anybody[test_length];
            anybody* women = new anybody[test_length];
            for (int i=0; i<test_length; i++)
            {
                getline (file, line);
                input += line + "\n";
                men[i].id = i;
                men[i].fiance = -1;
                men[i].free = true;
                men[i].preferences = new int[test_length];
                parse_preferences(line, men[i].preferences);
            }
            for (int i=0; i<test_length; i++)
            {
                getline (file, line);
                input += line + "\n";
                women[i].id = i;
                women[i].fiance = -1;
                women[i].free = true;
                women[i].preferences = new int[test_length];
                parse_preferences(line, women[i].preferences);
            }
            
            searchForWeddings(test_length, men, women);
            
            for (int i=0; i<test_length; i++)
            {
                output += to_string(men[i].id+1);
                output += " ";
                output += to_string(men[i].fiance+1);
                output += "\n";
            }
        }
    }
    cout << "\ninput:\n" << input;
    cout << "\noutput:\n" << output;
    getch();
    return 0;
}