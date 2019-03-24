#pragma once
#include "GraphicsComponent.h"

//TODO: igual que la puntuación --- empezar con un número y si da tiempo hacer que sea una barra de vida
class LivesViewer :
	public GraphicsComponent {
public:
	LivesViewer ();
	virtual ~LivesViewer ();
};

