#pragma once

class Gol_Rules: public Rules
{
    public:
        Gol_Rules() :: Rules(){};
        int get_nbNeigh(){return 8;}
        int get_radius(){return 1;}
}
