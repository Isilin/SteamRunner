#include "SoundEngine.hpp"
#include "./core/Data.hpp"
#include "EngineEvent.hpp"
#include <cstdlib>
using namespace std ;
#include <iostream>

SoundEngine::SoundEngine(Game* parent) : Engine(parent)
{
    _coreEngine = NULL ;
    _graphicEngine = NULL ;
    _soundEngine = this ;
    _clickBuffer.loadFromFile("./data/sound/Click.wav") ;
    _click.setBuffer(_clickBuffer) ;
    _volumeMusic = (float)((float)(Data::ToInt(Data::SearchInString(Data::Read("Save", "volumeMusic"),"value")))) ;
    _volumeSound = (float)((float)(Data::ToInt(Data::SearchInString(Data::Read("Save", "volumeSound"),"value")))) ;
    _click.setVolume(_volumeSound) ;
    _onMenu = false ;
    PlayMusicMenu() ;
}

SoundEngine::~SoundEngine()
{
    _playedBattleMusic.clear() ;
    _playedRushMusic.clear() ;
}

void SoundEngine::ChangeMusic(std::string typeMusic)
{
    int i = 0 ;
    if(typeMusic.compare("battle")==0)
    {
        i = rand()%8 ;
        while(In("_playedBattleMusic",i))
        {
            if(i==0)
            {
                i = 8 ;
            }
            else
            {
                 i-- ;
            }
        }
        _battleMusic.openFromFile(string("./data/music/Battle-").append(Data::ToString(i).append(".ogg"))) ;
        _battleMusic.play() ;
        _timerBattleMusic.restart() ;
        _playedBattleMusic.push_back(i) ;
        if(_playedBattleMusic.size()==8)
        {
            _playedBattleMusic.clear() ;
        }
    }
    else
    {
        i = rand()%6 ;
        while(In("_playedRushMusic",i))
        {
            if(i==0)
            {
                i = 6 ;
            }
            else
            {
                 i-- ;
            }
        }
        _rushMusic.openFromFile(string("./data/music/Rush-").append(Data::ToString(i).append(".ogg"))) ;
        _rushMusic.play() ;
        _timerRushMusic.restart() ;
        _playedTime = sf::Time::Zero ;
        _playedRushMusic.push_back(i) ;
        if(_playedRushMusic.size()==6)
        {
            _playedRushMusic.clear() ;
        }
    }
}

void SoundEngine::PlayMusicBattle()
{
    for(unsigned short int j=100;j>0;j--)
    {
        _rushMusic.setVolume((j/100)*_volumeMusic) ;
    }
    _rushMusic.pause() ;
    _playedTime += _timerRushMusic.getElapsedTime() ;
    int i = rand()%8 ;
    while(In("_playedBattleMusic",i))
    {
        if(i==0)
        {
            i = 8 ;
        }
        else
        {
             i-- ;
        }
    }
    _battleMusic.openFromFile(string("./data/music/Battle-").append(Data::ToString(i).append(".ogg"))) ;
    _battleMusic.play() ;
    _timerBattleMusic.restart() ;
    _playedBattleMusic.push_back(i) ;
    if(_playedBattleMusic.size()==8)
    {
        _playedBattleMusic.clear() ;
    }
    _battleMusic.setVolume(_volumeMusic) ;
}

void SoundEngine::PlayMusicRush()
{
    _onMenu = false ;
    _rushMusic.setLoop(false) ;
    if(_rushMusic.getStatus()==sf::SoundSource::Paused)
    {
        _battleMusic.stop() ;
        _rushMusic.play() ;
        _timerRushMusic.restart() ;
        for(unsigned short int i=0;i<100;i++)
        {
            _rushMusic.setVolume((i/100)*_volumeMusic) ;
        }
    }
    else
    {
        int i = rand()%6 ;
        while(In("_playedRushMusic",i))
        {
            if(i==0)
            {
                i = 6 ;
            }
            else
            {
                 i-- ;
            }
        }
        _rushMusic.openFromFile(string("./data/music/Rush-").append(Data::ToString(i).append(".ogg"))) ;
        _rushMusic.setVolume(_volumeMusic) ;
        _rushMusic.play() ;
        _timerRushMusic.restart() ;
        _playedRushMusic.push_back(i) ;
        if(_playedRushMusic.size()==6)
        {
            _playedRushMusic.clear() ;
        }
    }
}

void SoundEngine::PlayMusicMenu()
{
    if(!_onMenu)
    {
        _onMenu = true ;
        _rushMusic.stop() ;
        _rushMusic.openFromFile("./data/music/Menu.ogg") ;
        _rushMusic.play() ;
        _rushMusic.setVolume(_volumeMusic) ;
        _rushMusic.setLoop(true) ;
    }
}

void SoundEngine::PlaySound(string typeSound)
{
    if(typeSound.compare("start")==0)
    {
        _effectBuffer.loadFromFile("./data/sound/Start.wav") ;
    }
    else if(typeSound.compare("ore")==0 || typeSound.compare("vestige")==0)
    {
        _effectBuffer.loadFromFile("./data/sound/ding.wav") ;
    }
    else if(typeSound.compare("attack")==0)
    {
        _effectBuffer.loadFromFile("./data/sound/hit.wav") ;
    }
    else if(typeSound.compare("integrity")==0)
    {
        _effectBuffer.loadFromFile("./data/sound/reparation.wav") ;
    }
    else if(typeSound.compare("gatline")==0)
    {
        _effectBuffer.loadFromFile("./data/sound/gatline.wav") ;
    }
    else if(typeSound.compare("explosion")==0)
    {
        _effectBuffer.loadFromFile("./data/sound/explosion.wav") ;
    }
    else if(typeSound.compare("move")==0)
    {
        _effectBuffer.loadFromFile("./data/sound/move.wav") ;
    }
    else if(typeSound.compare("steam")==0 || typeSound.compare("pressure")==0)
    {
        _effectBuffer.loadFromFile("./data/sound/steam.wav") ;
    }
    else if(typeSound.compare("gun")==0)
    {
        _effectBuffer.loadFromFile("./data/sound/gun.wav") ;
    }
    else if(typeSound.compare("snare")==0)
    {
        _effectBuffer.loadFromFile("./data/sound/snare.wav") ;
    }
    _effect.setBuffer(_effectBuffer) ;
        _effect.play() ;
}

void SoundEngine::PlayClick()
{
    _click.play() ;
}

bool SoundEngine::In(string typeVector, int i)
{
    if(typeVector.compare("playedBattleMusic")==0)
    {
        for (unsigned short int j=0;j<_playedBattleMusic.size();j++)
        {
            if(_playedBattleMusic[j]==i)
            {
                return true;
            }
        }

    }
    else
    {
        for (unsigned short int j=0;j<_playedRushMusic.size();j++)
        {
            if(_playedRushMusic[j]==i)
            {
                return true;
            }
        }
    }
    return false ;
}

void SoundEngine::Frame()
{
    if(_rushMusic.getStatus()==sf::SoundSource::Paused)
    {
        if(_timerBattleMusic.getElapsedTime()>=_battleMusic.getDuration())
        {
            ChangeMusic("battle") ;
        }
    }
    else if(!_onMenu)
    {
        if(_timerRushMusic.getElapsedTime()+_playedTime>_rushMusic.getDuration())
        {
            ChangeMusic("rush") ;
        }
    }
}


void SoundEngine::ProcessEvent(const EngineEvent* event)
{
    if(event->_type.compare("menu")==0)
    {
        PlayMusicMenu() ;
    }
    else if(event->_type.compare("click")==0)
    {
        PlayClick() ;
    }
    else if(event->_type.compare("battle")==0)
    {
        PlayMusicBattle() ;
    }
    else if(event->_type.compare("rush")==0)
    {
        PlayMusicRush() ;
    }
    else if(event->_type.compare("start")==0)
    {
        PlaySound("start") ;
    }
    else if(event->_type.compare("menu")==0)
    {
        PlayMusicMenu() ;
    }
    else if(event->_type.compare("volumeMusic")==0)
    {
        _rushMusic.setVolume(event->_intData.at("value")) ;
        Data::Write("volumeMusic",event->_intData.at("value")) ;
    }
    else if(event->_type.compare("volumeSound")==0)
    {
        _battleMusic.setVolume(event->_intData.at("value")) ;
        Data::Write("volumeSound",event->_intData.at("value")) ;
    }
    else if(event->_type.compare("sound")==0)
    {
        PlaySound(event->_stringData.at("type")) ;
    }


}
