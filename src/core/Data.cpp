/**
 * @file     Data.cpp
 * @author   Damien Claras
 * @author   Pierre Casati
 * @version  v0.1dev
 * @date     2014, may 15th
 * @brief    Methods of class Data.
 */

#include "Data.hpp"
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std ;

vector<string> Data::_playerTxt ;
vector<string> Data::_saveTxt ;
vector<string> Data::_mobmineTxt ;
vector<string> Data::_mobjungleTxt ;
vector<string> Data::_mobdesertTxt ;
vector<string> Data::_tutorielTxt ;
vector<string> Data::_creditTxt ;
vector<string> Data::_roomTxt ;

string Data::Read(const string type, string keys)
{
    unsigned int i = 0;
    if(type.compare("Room")==0)
    {
        while(i<_roomTxt.size())
        {
            if(SearchInString(_roomTxt[i], "type").compare(keys)==0)
            {
                return _roomTxt[i] ;
            }
            i++ ;
        }
    }
    else if(type.compare("PartMobDesert")==0)
    {
        while(i<_mobdesertTxt.size())
        {
            if(SearchInString(_mobdesertTxt[i], "type").compare(keys)==0)
            {
                return _mobdesertTxt[i] ;
            }
            i++ ;
        }
    }
    else if(type.compare("PartMobJungle")==0)
    {
        while(i<_mobjungleTxt.size())
        {
            if(SearchInString(_mobjungleTxt[i], "type").compare(keys)==0)
            {
                return _mobjungleTxt[i] ;
            }
            i++ ;
        }
    }
    else if(type.compare("PartMobMine")==0)
    {
        while(i<_mobmineTxt.size())
        {
            if(SearchInString(_mobmineTxt[i], "type").compare(keys)==0)
            {
                return _mobmineTxt[i] ;
            }
            i++ ;
        }
    }
    else if(type.compare("Credit")==0)
    {
        return _creditTxt[0] ;
    }
    else if(type.compare("Tutoriel")==0)
    {
       return _tutorielTxt[0] ;
    }
    else if(type.compare("PlayerPart")==0)
    {
        if(keys.substr(0,7).compare("leftArm")==0)
        {
            keys = string("a").append(keys.substr(5,string::npos)) ;
        }
        while(i<_playerTxt.size())
        {
            if(SearchInString(_playerTxt[i], "type").compare(keys)==0)
            {
                return _playerTxt[i] ;
            }
            i++ ;
        }
    }
    else if(type.compare("Save")==0)
    {
        while(i<_saveTxt.size())
        {
            if(SearchInString(_saveTxt[i], "type").compare(keys)==0)
            {
                return _saveTxt[i] ;
            }
            i++ ;
        }
    }
    return "" ;
}

void Data::InitData()
{
    string ligne = "" ;
    ifstream fichier ;
    fichier.open("./data/txt/Room.txt", ios::in) ;
    while(getline(fichier,ligne))
    {
        _roomTxt.push_back(ligne) ;
    }
    fichier.close() ;
    fichier.open("./data/txt/Save.txt", ios::in) ;
    while(getline(fichier,ligne))
    {
        _saveTxt.push_back(ligne) ;
    }
    fichier.close() ;
    fichier.open("./data/txt/Player.txt", ios::in) ;
    while(getline(fichier,ligne))
    {
        _playerTxt.push_back(ligne) ;
    }
    fichier.close() ;
    fichier.open("./data/txt/MobDesert.txt", ios::in) ;
    while(getline(fichier,ligne))
    {
        _mobdesertTxt.push_back(ligne) ;
    }
    fichier.close() ;
    fichier.open("./data/txt/MobMine.txt", ios::in) ;
    while(getline(fichier,ligne))
    {
        _mobmineTxt.push_back(ligne) ;
    }
    fichier.close() ;
    fichier.open("./data/txt/MobJungle.txt", ios::in) ;
    while(getline(fichier,ligne))
    {
        _mobjungleTxt.push_back(ligne) ;
    }
    fichier.close() ;
    fichier.open("./data/txt/Tutoriel.txt", ios::in) ;
    while(getline(fichier,ligne))
    {
        _tutorielTxt.push_back(ligne) ;
    }
    fichier.close() ;
    fichier.open("./data/txt/Credit.txt", ios::in) ;
    while(getline(fichier,ligne))
    {
        _creditTxt.push_back(ligne) ;
    }
    unsigned int tmp = 0, i = 0 ;
    while(i<_roomTxt.size())
    {
        tmp = 0;
        while (tmp!=string::npos)
        {

            tmp = _roomTxt[i].find("$", tmp) ;
            if (tmp!=string::npos)
            {
                _roomTxt[i].replace(tmp, 1, string("\n")) ;
                tmp = tmp+1;
            }
        }
        i++;
    }
    tmp = 0, i = 0 ;
    while(i<_creditTxt.size())
    {
        tmp = 0;
        while (tmp!=string::npos)
        {

            tmp = _creditTxt[i].find("$", tmp) ;
            if (tmp!=string::npos)
            {
                _creditTxt[i].replace(tmp, 1, string("\n")) ;
                tmp = tmp+1;
            }
        }
        i++;
    }
    tmp = 0, i = 0 ;
    while(i<_playerTxt.size())
    {
        tmp = 0;
        while (tmp!=string::npos)
        {

            tmp = _playerTxt[i].find("$", tmp) ;
            if (tmp!=string::npos)
            {
                _playerTxt[i].replace(tmp, 1, string("\n")) ;
                tmp = tmp+1;
            }
        }
        i++;
    }
}

void Data::SaveData()
{
    unsigned int tmp = 0, i = 0 ;
    while(i<_roomTxt.size())
    {
        tmp = 0;
        while (tmp!=string::npos)
        {

            tmp = _roomTxt[i].find("\n", tmp) ;
            if (tmp!=string::npos)
            {
                _roomTxt[i].replace(tmp, 1, string("$")) ;
                tmp = tmp+1;
            }
        }
        i++;
    }
    tmp = 0, i = 0 ;
    while(i<_playerTxt.size())
    {
        tmp = 0;
        while (tmp!=string::npos)
        {

            tmp = _playerTxt[i].find("\n", tmp) ;
            if (tmp!=string::npos)
            {
                _playerTxt[i].replace(tmp, 1, string("$")) ;
                tmp = tmp+1;
            }
        }
        i++;
    }
    ofstream fichier ;
    fichier.open("./data/txt/Save.txt", ios::trunc) ;
    for(unsigned short int i=0;i<_saveTxt.size();i++)
    {
        fichier<<_saveTxt[i]<<'\n' ;
    }
    fichier.close() ;
    fichier.open("./data/txt/Player.txt", ios::trunc) ;
    for(unsigned short int i=0;i<_playerTxt.size();i++)
    {
        fichier<<_playerTxt[i]<<'\n' ;
    }
    fichier.close() ;
}

void Data::CloseData()
{
    _playerTxt.clear() ;
    _saveTxt.clear() ;
    _mobmineTxt.clear() ;
    _mobjungleTxt.clear() ;
    _mobdesertTxt.clear() ;
    _tutorielTxt.clear() ;
    _creditTxt.clear() ;
    _roomTxt.clear() ;
}

void Data::Reset()
{
    unsigned int i ;
    int position = 0, tmp ;
    for(i=1;i<_playerTxt.size();i++)
    {
        tmp = _playerTxt[i].find("level") + 6 ;
        _playerTxt[i].replace(tmp, _playerTxt[i].find("~", tmp)-tmp, ToString(1)) ;
        for(int j=0;_playerTxt[i].find(string("effects").append(ToString(j)))!= string::npos;j++)
        {
            position=_playerTxt[i].find(string("effects").append(ToString(j))) ;
            for(int k=0;_playerTxt[i].find(string("value").append(ToString(k)), position)!= string::npos;k++)
            {
                tmp = _playerTxt[i].find(string("value").append(ToString(k)), position) + 7 ;
                _playerTxt[i].replace(tmp,
                                      _playerTxt[i].find("~", tmp) - tmp,
                                       SearchInString(_playerTxt[i].substr(position),string("initialeValue").append(ToString(k)))) ;
            }
        }
    }
    position = 0 ;
    for(i=0;i<9;i++)
    {
        if(i==0)
        {
            tmp = _saveTxt[i].find("value") + 7 ;
            _saveTxt[i].replace(tmp, _saveTxt[i].find("~", tmp)-tmp, ToString(0)) ;
        }
        else
        {
            tmp = _saveTxt[i].find("level") + 6 ;
            _saveTxt[i].replace(tmp, _saveTxt[i].find("~", tmp)-tmp, ToString(1)) ;

            for(int j=0;_saveTxt[i].find(string("value").append(ToString(j)))!= string::npos;j++)
            {
                tmp = _saveTxt[i].find(string("value").append(ToString(j))) + 7 ;
                _saveTxt[i].replace(tmp,
                                      _saveTxt[i].find("~", tmp) - tmp,
                                       SearchInString(_saveTxt[i], string("initialeValue").append(ToString(j)))) ;
            }
        }
    }
}

void Data::Upgrade(const string type, const string keys)
{
    unsigned short int i = 0 ;
    int position = 0, tmp ;
    bool worked = false ;
    if(type.compare("PlayerPart")==0)
    {
        while(!worked && i<_playerTxt.size())
        {
            if(SearchInString(_playerTxt[i], "type").compare(keys)==0&& ToInt(SearchInString(_playerTxt[i], "level"))<ToInt(SearchInString(_playerTxt[i], "maxLevel")))
            {
                tmp = _playerTxt[i].find("level") + 6 ;
                _playerTxt[i].replace(tmp, _playerTxt[i].find("~", tmp)-tmp, ToString(ToInt(SearchInString(_playerTxt[i], "level"))+1)) ;

                for(int j=0;_playerTxt[i].find(string("effects").append(ToString(j)))!= string::npos;j++)
                {
                    position=_playerTxt[i].find(string("effects").append(ToString(j))) ;
                    for(int k=0;_playerTxt[i].find(string("value").append(ToString(k)), position)!= string::npos;k++)
                    {
                        tmp = _playerTxt[i].find(string("value").append(ToString(k)), position) + 7 ;
                        _playerTxt[i].replace(tmp,
                                              _playerTxt[i].find("~", tmp) - tmp,
                                               ToString(ToInt(SearchInString(_playerTxt[i].substr(position),string("value").append(ToString(k)))) + ToInt(SearchInString(_playerTxt[i].substr(position),string("perLevel").append(ToString(k)))))) ;
                    }
                }
                worked = true ;
            }
            i++ ;
        }
    }
    else if(type.compare("Save")==0)
    {
        while(!worked && i<_saveTxt.size())
        {
            if(SearchInString(_saveTxt[i], "type").compare(keys)==0)
            {
                if(ToInt(SearchInString(_saveTxt[i], "level"))<ToInt(SearchInString(_saveTxt[i], "maxLevel")) || ToInt(SearchInString(_saveTxt[i], "maxLevel"))==0)
                {
                    tmp = _saveTxt[i].find("level") + 6 ;
                    _saveTxt[i].replace(tmp, _saveTxt[i].find("~", tmp)-tmp, ToString(ToInt(SearchInString(_saveTxt[i], "level"))+1)) ;
                    for(int j=0;_saveTxt[i].find(string("value").append(ToString(j)))!= string::npos;j++)
                    {
                        tmp = _saveTxt[i].find(string("value").append(ToString(j))) + 7 ;
                        _saveTxt[i].replace(tmp,
                                              _saveTxt[i].find("~", tmp) - tmp,
                                               ToString(ToInt(SearchInString(_saveTxt[i], string("value").append(ToString(j)))) + ToInt(SearchInString(_saveTxt[i], string("perLevel").append(ToString(j)))))) ;
                    }
                    worked = true ;
                }
            }
            i++ ;
        }
    }
}

void Data::Write(const string keys, int value)
{
    for(unsigned short int i=0;i<_saveTxt.size();i++)
    {
        if(keys.compare(SearchInString(_saveTxt[i],"type"))==0)
        {
            int position = _saveTxt[i].find("value") + 1 ;
            _saveTxt[i].replace(position, _saveTxt[0].find(string("~"), position) - position, ToString(value)) ;
        }
    }
}

string Data::SearchInString(const string myString, const string mySearch, bool tildDoubled)
{
    if(tildDoubled)
    {
        int position = myString.find(mySearch) + mySearch.size()+1 ;
        return myString.substr(position, myString.find(string("~~"), position)-position) ;
    }
    else
    {
        int position = myString.find(mySearch) + mySearch.size()+1 ;
        return myString.substr(position, myString.find(string("~"), position)-position) ;
    }
}

string Data::ToString(const int r)
{
    ostringstream oss ;
    oss<<r;
    return oss.str() ;
}

int Data::ToInt(const string s)
{
    int r ;
    istringstream iss(s) ;
    iss>>r ;
    return r;
}

vector<string> Data::SplitString(string myString, string mySplit)
{
    vector<string> myVector ;
    unsigned int position = 0, tmp ;
    bool worked = false ;
    while(!worked)
    {
        tmp = myString.find(mySplit, position) ;
        if(tmp!=string::npos)
        {
            myVector.push_back(myString.substr(position, tmp-position)) ;
            position += tmp-position + mySplit.size() ;
        }
        else
        {
            myVector.push_back(myString.substr(position)) ;
            worked = true ;
        }
    }
    return myVector ;
}
