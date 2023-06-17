#pragma once
#include <vector>
#include "Camera.h"
#include "ModelLoader.h"
#include "Model.h"
#include "Cuboid.h"
#include "Text.h"
#include "Player.h"
#include "Enemy.h"
#include "Obstacle.h"

using namespace std;

class Scene
{
private:
	bool drawVertexes, drawBox;

protected:
	Camera camera;
	vector<Solid *> gameObjects;
	Vector3D boundary;

	float desplazamiento, incremento;
	vector<Solid *> vias; // Trenes y vias
	vector<Obstacle*> obstaculos;
	ModelLoader *loader, *loaderVias, *loaderLvl1, *loaderLvl2, *loaderLvl3, *loaderPersonaje;
	Model *via, *tren;
	Obstacle *obstaculo;
	Player *jugador;
	Enemy *enemigo;

public:
	Scene(Vector3D boundaryArgument = Vector3D(10, 8, 10), bool drawVertexesArgument = false, bool drawBoxArgument = true) : 
		boundary(boundaryArgument), drawVertexes(drawVertexesArgument), drawBox(drawBoxArgument){};

	// GETTERS
	inline Vector3D GetBoundary() const { return this->boundary; }
	inline bool GetDrawVertexes() const { return this->drawVertexes; }
	inline bool GetDrawBox() const { return this->drawBox; }

	// SETTER
	inline void SetBoundary(const Vector3D &boundaryToSet) { this->boundary = boundaryToSet; }
	inline void SetDrawVertexes(const bool &drawVertexesToSet) { this->drawVertexes = drawVertexesToSet; }
	inline void SetDrawBox(const bool &drawBoxToSet) { this->drawBox = drawBoxToSet; }

	// SETTERS Y GETTERS DE LA CAMARA.
	inline Camera GetCamera() const { return this->camera; }
	inline void SetCamera(const Camera &cameraToSet) { this->camera = cameraToSet; }

	// OTROS METODOS
	inline void AddGameObject(Solid *gameObject) { this->gameObjects.push_back(gameObject); }
	inline void AddVia(Solid *via) { this->vias.push_back(via); }
	inline void AddObstaculo(Obstacle *obstaculo) { this->obstaculos.push_back(obstaculo); }
	inline void AddPersonaje(Player *personaje) { this->jugador = personaje; }

	void Init();
	void Render();
	virtual void Update(const float &timeIncrement);

	virtual void Reset();
	virtual int CheckStatus();

	virtual void ProcessKeyPressed(unsigned char key, int px, int py);
	void ProcessMouseMovement(int x, int y);
	void ProcessMouseClick(int button, int state, int x, int y);
};