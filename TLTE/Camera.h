#pragma once
#include<GL/glew.h>
#include<GL/freeglut.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

#include <iostream>
using namespace glm;
using namespace	std;
class Camera
{
	
public:
	Camera();
	Camera(const vec3& Pos, const vec3& Target, const vec3& Up);
	bool OnKeyboard(int Key);
	void OnMouse(int x, int y);
	const vec3& GetPos() const;
	//const double& GetPosX() const;
	//const double& GetPosY() const;
	//const double& GetPosZ() const;
	const vec3& GetTarget() const;
	const vec3& GetUp() const;
	float GetX()const;
	float GetY()const;
	void SetY(float y);
	//void Update();
private:
	bool m_OnLeftEdge = false;
	bool m_OnRightEdge = false;
	bool m_OnUpperEdge = false;
	bool m_OnLowerEdge = false;
	vec3 m_pos;
	vec3 m_target;
	vec3 m_up;
	vec2 m_mousePos;
	float m_AngleH,
		m_AngleV;
	float StepSize = 1;
	int MARGIN = 10;
	int m_windowWidth = 800;
	int m_windowHeight = 600;

};

