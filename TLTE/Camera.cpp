#include "Camera.h"



Camera::Camera()
{
}

Camera::Camera(const vec3& Pos, const vec3& Target, const vec3& Up) 
{
	m_pos = Pos;
	m_target=Target ;
	m_up = Up;
	m_AngleH = 0; 
	m_AngleV = 0;
	m_mousePos = vec2(0, 0);
}
float Camera::GetX()const { return m_AngleH; }
float Camera::GetY()const { return m_AngleV; }
void Camera::SetY(float y)
{
	m_pos.y = y;
}
void Camera::OnMouse(int x, int y)
{
	const int DeltaX = x - m_mousePos.x;
	const int DeltaY = y - m_mousePos.y;

	m_mousePos.x = x;
	m_mousePos.y = y;

	m_AngleH += (float)DeltaX / 20.0f;
	m_AngleV += (float)DeltaY / 20.0f;

	if (DeltaX == 0) {
		if (x <= MARGIN) {
			m_OnLeftEdge = true;
		}
		else if (x >= (m_windowWidth - MARGIN)) {
			m_OnRightEdge = true;
		}
	}
	else {
		m_OnLeftEdge = false;
		m_OnRightEdge = false;
	}

	if (DeltaY == 0) {
		if (y <= MARGIN) {
			m_OnUpperEdge = true;
		}
		else if (y >= (m_windowHeight - MARGIN)) {
			m_OnLowerEdge = true;
		}
	}
	else {
		m_OnUpperEdge = false;
		m_OnLowerEdge = false;
	}

	
}

bool Camera::OnKeyboard(int Key)
{
	bool Ret = false;

	switch (Key) {

	case GLUT_KEY_UP:
	{
		m_pos += (m_target * StepSize);
		Ret = true;
		//cout << "up pressed" << endl;
	}
	
	break;

	case GLUT_KEY_DOWN:
	{
		m_pos -= (m_target * StepSize);
		Ret = true;
		//cout << "Down pressed" << endl;
	}
		break;
		
	case GLUT_KEY_LEFT:
	{
		vec3 Left = cross(m_up, m_target);
		normalize(Left);
		Left *= StepSize;
		m_pos += Left;
		Ret = true;
		//cout << "Left pressed" << endl;
	}
	break;

	case GLUT_KEY_RIGHT:
	{
		vec3 Right = cross(m_up,m_target);
		normalize(Right);
		Right *= StepSize;
		m_pos -= Right;
		Ret = true;
		//cout << "Right pressed" << endl;
	}
	break;
	}

return Ret;
}

const vec3& Camera::GetPos() const 
{
	return m_pos;
}

//const double& Camera::GetPosX() const { r}
//const double& Camera::GetPosY() const {}
//const double& Camera::GetPosZ() const {}
const vec3& Camera::GetTarget() const 
{
	return m_target;
}
const vec3& Camera::GetUp() const
{
	return m_up;
}



