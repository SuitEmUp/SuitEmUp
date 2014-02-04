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

		if(fabs(Z) <= Q+P) // ändrar här till =
		{
			float dx = ceilf(fabs(C) - (A+B));
			float dy = ceilf(fabs(Z) - (Q+P));
			if (dx >= dy) // här också
			{
				if (m_position.x < p_other.m_position.x) //bytte > till < här
				{
					dx = -dx;
				}
				p_offset.x = dx;
				//p_other.m_position.m_x += dx;
				//jag ser här att det står p_other.m_position.m_x += dx; 
				//också vettefan varför dock

			}else
			{
				if(m_position.x > p_other.m_position.y)
				{
					dy = - dy;

				}
				p_offset.y = dy;
				//p_other.m_position.m_y += dy;
				//samma här, undrar varför - han += på dx och dy på p_other.m_position.m_y
				// till något men jag vet inte vad han kan ha för användning av detr senare.
				//måste vara att han fixar collision senare med det.
			}

			return true;
		}


	}
	return false;
}
