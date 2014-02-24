// EyeCandy.h

#pragma once

#include <vector>
#include <string>
#include <SFML\Window.hpp>

class Particles;
class Picture;

class EyeCandy{
public:
	EyeCandy();
	~EyeCandy();

	Particles* ParticlesCreator(std::string* p_type);
	Picture* PictureCreator();

	void ParticlesDestroyer(std::vector<Particles*> p_particles);
	void PictureDestroyer(std::vector<Picture*> p_pictures);

	sf::Vector2f position;
};