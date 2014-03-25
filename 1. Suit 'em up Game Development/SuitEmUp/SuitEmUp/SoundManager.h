#include <String>
#include <vector>
#include <SFML/Audio.hpp>
#pragma once

struct SoundStruct
{
	std::string path;
	sf::Sound* sounddata;
	sf::SoundBuffer* buffer;
};

struct MusicStruct{
	std::string path;
	sf::Music* musicdata;
};

class SoundManager
{
public:
	SoundManager(void);
	~SoundManager(void);
	bool Initialize(std::string path);
	void PlaySound(std::string path);
	void PlayMusic(std::string path);
	void StopMusic(std::string path);

	void SetMusicVolume(float volume);
	void SetSoundVolume(float volume);
	void SetMasterVolume(float volume);
	
	float GetSoundVolume();
	float GetMusicVolume();
	float GetMasterVolume();

private:

	float m_musicvolume;
	float m_soundvolume;
	float m_mastervolume;
	std::string m_directory;

	void AddSound(std::string path);
	void AddMusic(std::string path);

	std::vector<SoundStruct> m_sounds;
	std::vector<MusicStruct> m_musics;


};

