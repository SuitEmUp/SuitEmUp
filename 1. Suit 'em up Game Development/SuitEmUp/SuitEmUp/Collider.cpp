// Collider.cpp


#include <cmath>
#include "Collider.h"
#include "GameObject.h"
#include "GameObjectManager.h"
//#include "Level.h"
#include <iostream>

Collider::Collider()
	: m_position(0.0f, 0.0f)
	, m_extension(0.0f, 0.0f)
{
}
Collider::~Collider()
{
}
void Collider::NotifyParent(GameObject* go1)
{

	go1->SetPosition(go1->GetPosition().x, go1->GetPosition().y);
}

Collider::Collider(const sf::Vector2f &p_position, const sf::Vector2f &p_extension)
	: m_position(p_position)
	, m_extension(p_extension)
{
}

bool Collider::Overlap(const Collider &p_other, sf::Vector2f &p_offset)
{
	float A = m_extension.x * 0.5f;
	float B = p_other.m_extension.x *0.5f;
	float C = (m_position.x + A) - (p_other.m_position.x + B);

	if(fabs(C) < A+B)
	{
		float Q = m_extension.y *0.5f;
		float P = p_other.m_extension.y *0.5f;
		float Z = (m_position.y + Q ) - ( p_other.m_position.y + P);

		if(fabs(Z) <= Q+P) // �ndrar h�r till =
		{
			float dx = ceilf(fabs(C) - (A+B));
			float dy = ceilf(fabs(Z) - (Q+P));
			if (dx >= dy) // h�r ocks�
			{
				if (m_position.x < p_other.m_position.x) //bytte > till < h�r
				{
					dx = -dx;
				}
				p_offset.x = dx;
				//p_other.m_position.m_x += dx;
				//jag ser h�r att det st�r p_other.m_position.m_x += dx; 
				//ocks� vettefan varf�r dock

			}else
			{
				if(m_position.x > p_other.m_position.y)
				{
					dy = - dy;

				}
				p_offset.y = dy;
				//p_other.m_position.m_y += dy;
				//samma h�r, undrar varf�r - han += p� dx och dy p� p_other.m_position.m_y
				// till n�got men jag vet inte vad han kan ha f�r anv�ndning av detr senare.
				//m�ste vara att han fixar collision senare med det.
			}

			return true;
		}


	}
	return false;
}
