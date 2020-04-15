#include "./Constants.h"
#include "./Gex.h"


int main(int argc, char *argv[]) {
    Gex *gex = new Gex();

    gex->Initialize(WIN_WIDTH, WIN_HEIGHT);

    while (gex->IsRunning()) {
        gex->ProcessInput();
        gex->Update();
        gex->Render();
    }

    gex->Destroy();

    return 0;
}
