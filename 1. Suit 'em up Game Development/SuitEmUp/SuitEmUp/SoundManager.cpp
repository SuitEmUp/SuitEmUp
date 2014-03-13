#include "SoundManager.h"


SoundManager::SoundManager(void)
{
}


SoundManager::~SoundManager(void)
{
}

bool SoundManager::Initialize(std::string path)
{
	m_mastervolume = 1;
	m_musicvolume = 1;
	m_soundvolume = 1;
	m_directory = path;
	return true;
};

void SoundManager::PlaySound(std::string path)
{
	if(m_sounds.size()>0)
	{
		for(SoundStruct sound : m_sounds)
		{
			if(sound.path == path){
				sound.sounddata->setVolume(m_soundvolume*m_mastervolume);
				sound.sounddata->play();
				return;
			}
		}
	}
	AddSound(path);
	PlaySound(path);
};

void SoundManager::PlayMusic(std::string path)
{
	if(m_musics.size()>0)
	{
		for(MusicStruct music : m_musics){
			if(music.path == path){
				music.musicdata->setVolume(m_musicvolume*m_mastervolume);
				music.musicdata->play();
				return;
			}
		}
	}
	AddMusic(path);
	PlayMusic(path);
};

void SoundManager::StopMusic(){};

void SoundManager::SetMusicVolume(float volume){
	m_musicvolume = volume;
};
void SoundManager::SetSoundVolume(float volume){
	m_soundvolume = volume;
};
void SoundManager::SetMasterVolume(float volume){
	m_mastervolume = volume/100;
};

float SoundManager::GetSoundVolume(){
return 0;};
float SoundManager::GetMusicVolume(){return 0;};
float SoundManager::GetMasterVolume(){return 0;};

void SoundManager::AddSound(std::string path)
{
	SoundStruct soundstruct;
	sf::Sound* sound = new sf::Sound;
	sf::SoundBuffer* buffer = new sf::SoundBuffer;
	buffer->loadFromFile(m_directory + path);
	sound->setBuffer(*buffer);
	soundstruct.path = path;
	soundstruct.sounddata = sound;
	soundstruct.buffer = buffer;

	m_sounds.push_back(soundstruct);

};
void SoundManager::AddMusic(std::string path)
{
	MusicStruct musicstruct;
	sf::Music* music = new sf::Music;
	music->openFromFile(m_directory + path);
	musicstruct.path = path;
	musicstruct.musicdata = music;

	m_musics.push_back(musicstruct);
};