#include "terrain.h"


balle terrain::balleDuTerrain() const
{
    return d_balle;
}

palet terrain::paletDuTerrain() const
{
    return d_palet;
}

const surfaceRebondissante* terrain::SurfaceNumero(int i) const
{
    return d_surfaceRebondissantes[i].get();
}

std::unique_ptr<surfaceRebondissante> terrain::SurfaceNumero(int i)
{
    return std::move(d_surfaceRebondissantes[i]);
}
