#include "GLWindow.h"
#include "Integrator.h"


/******************************************************************************
 * MAIN ROUTINE
 *****************************************************************************/
int main(int argc, char *argv[])
{
    // Parameters
    const int row = 5;
    const int col = 5;
	const int depth = 1;
    double step = 0.01;

    // Simulation parameters
    CDeformableObject deform;
    deform.setStiffness(-50);
    deform.setDamping(-1);
    deform.setMass(1);
    deform.setTimeStep(0.01);

    deform.loadObjFile("bunny.obj");    

    CRigidSphere rigidSphere;
    rigidSphere.setPosition(-0.8, 0, 0);
    rigidSphere.setDiameter(0.6);
    rigidSphere.setVirtualStiffness(-1000.0);
    rigidSphere.setVirtualDamping(-1);

    CIntegrator integrator;
    integrator.addDeformableObject(&deform);
    integrator.addRigidSphere(&rigidSphere);
    integrator.execSimThread();

    // Prepare graphic thingy
    glwSetRigidSphereStep(0.005);
    glwDeformableObjectToDraw(&deform);
    glwRigidSphereToDraw(&rigidSphere);    
    glwGraphInit(argc, argv, "Deformable Object");    
    
    return 0;
}



