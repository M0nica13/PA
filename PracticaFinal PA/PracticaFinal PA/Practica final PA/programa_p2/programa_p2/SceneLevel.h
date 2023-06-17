#pragma once
#include "Scene.h"
#include <vector>
#include "Camera.h"
#include "ModelLoader.h"
#include "Model.h"
#include "Cuboid.h"
#include <iostream>
class SceneLevel : public Scene
{
private:
    int nivel;
    Cuboid *meta;
    bool activo, estadoGanar, estadoPerder;
    void checkBoundary();

public:
    SceneLevel(bool activoArgument = true, int nivelToSet = 1) : 
    Scene(), activo(activoArgument), nivel(nivelToSet), estadoGanar(false), estadoPerder(false)
    {
        std::cout << "Constructor del nivel " << nivel << std::endl;
    }

    void Init();

    inline void SetNivel(const int &nivelToSet) { this->nivel = nivelToSet; }; // DEPRECATED - Revisar
    inline void SetMeta(Cuboid *metaToSet) { this->meta = metaToSet; }
    inline void SetActivo(bool activoToSet) { this->activo = activoToSet; } // DEPRECATED - Revisar
    inline void SetStatus(bool statusToSet) { this->estadoGanar = statusToSet; this->estadoPerder = statusToSet; } // DEPRECATED - Revisar

    int CheckStatus();
    void Update(const float &timeIncrement);
    void checkColisiones();
    void ProcessKeyPressed(unsigned char key, int px, int py);

    void haPerdido();
    void haGanado();

    void Reset();
};
