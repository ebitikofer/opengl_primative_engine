#ifndef GAME_H
#define GAME_H

void render_models(/*MatrixStack stack,*/bool heal, bool hurt, bool strengthen, bool weaken, bool resupply, bool energize, bool hallucinate, color4 aps[], color4 dps[], color4 sps[], color4 light_ambients[], color4 light_diffuses[], color4 light_speculars[], GLuint ambient_product, GLuint diffuse_product, GLuint specular_product, GLuint ambient_product2, GLuint diffuse_product2, GLuint specular_product2, GLuint enable, float color_a_pink, color4 emissive[], GLuint Material_Emiss, GLuint shiny) {

  if (render_[FLOORS]) {
    for (int i = 0; i < NUM_FLOORS; i++) {
      for (int j = 0; j < PARTS_FLOOR; j++) {
        floors[i][j].render(/*mvstack*/ heal, hurt, strengthen, weaken, resupply, energize, hallucinate, aps, dps, sps, light_ambients, light_diffuses, light_speculars, ambient_product, diffuse_product, specular_product, ambient_product2, diffuse_product2, specular_product2, enable, color_a_pink, emissive, Material_Emiss, shiny);
      }
    }
  }

  // if (render_[MOONS]) {
  //   for (int i = 0; i < NUM_MOONS; i++) {
  //     for (int j = 0; j < PARTS_MOON; j++) {
  //       moons[i][j].render(/*mvstack*/ heal, hurt, strengthen, weaken, resupply, energize, hallucinate, aps, dps, sps, light_ambients, light_diffuses, light_speculars, ambient_product, diffuse_product, specular_product, ambient_product2, diffuse_product2, specular_product2, enable, color_a_pink, emissive, Material_Emiss, shiny);
  //     }
  //   }
  // }

  if (render_[GUNS]) {
    for (int i = 0; i < NUM_GUNS; i++) {
      for (int j = 0; j < PARTS_GUN; j++) {
        guns[i][j].render(/*mvstack*/ heal, hurt, strengthen, weaken, resupply, energize, hallucinate, aps, dps, sps, light_ambients, light_diffuses, light_speculars, ambient_product, diffuse_product, specular_product, ambient_product2, diffuse_product2, specular_product2, enable, color_a_pink, emissive, Material_Emiss, shiny);
      }
    }
  }

  if (render_[KEYS]) {
    for (int i = 0; i < NUM_KEYS; i++) {
      for (int j = 0; j < PARTS_KEY; j++) {
        keys[i][j].render(/*mvstack*/ heal, hurt, strengthen, weaken, resupply, energize, hallucinate, aps, dps, sps, light_ambients, light_diffuses, light_speculars, ambient_product, diffuse_product, specular_product, ambient_product2, diffuse_product2, specular_product2, enable, color_a_pink, emissive, Material_Emiss, shiny);
      }
    }
  }

  if (render_[VACCUUMS]) {
    for (int i = 0; i < NUM_VACCUUMS; i++) {
      for (int j = 0; j < PARTS_VACCUUM; j++) {
        vaccuums[i][j].render(/*mvstack*/ heal, hurt, strengthen, weaken, resupply, energize, hallucinate, aps, dps, sps, light_ambients, light_diffuses, light_speculars, ambient_product, diffuse_product, specular_product, ambient_product2, diffuse_product2, specular_product2, enable, color_a_pink, emissive, Material_Emiss, shiny);
      }
    }
  }

  if (render_[COFFEES]) {
    for (int i = 0; i < NUM_COFFEES; i++) {
      for (int j = 0; j < PARTS_COFFEE; j++) {
        coffees[i][j].render(/*mvstack*/ heal, hurt, strengthen, weaken, resupply, energize, hallucinate, aps, dps, sps, light_ambients, light_diffuses, light_speculars, ambient_product, diffuse_product, specular_product, ambient_product2, diffuse_product2, specular_product2, enable, color_a_pink, emissive, Material_Emiss, shiny);
      }
    }
  }

  if (render_[BULLETS]) {
    for (int i = 0; i < NUM_BULLETS; i++) {
      for (int j = 0; j < PARTS_BULLET; j++) {
        bullets[i][j].render(/*mvstack*/ heal, hurt, strengthen, weaken, resupply, energize, hallucinate, aps, dps, sps, light_ambients, light_diffuses, light_speculars, ambient_product, diffuse_product, specular_product, ambient_product2, diffuse_product2, specular_product2, enable, color_a_pink, emissive, Material_Emiss, shiny);
      }
    }
  }

  if (render_[ROCKETS]) {
    for (int i = 0; i < NUM_ROCKETS; i++) {
      for (int j = 0; j < PARTS_ROCKET; j++) {
        rockets[i][j].render(/*mvstack*/ heal, hurt, strengthen, weaken, resupply, energize, hallucinate, aps, dps, sps, light_ambients, light_diffuses, light_speculars, ambient_product, diffuse_product, specular_product, ambient_product2, diffuse_product2, specular_product2, enable, color_a_pink, emissive, Material_Emiss, shiny);
      }
    }
  }

  if (render_[HEALTHS]) {
    for (int i = 0; i < NUM_HEALTHS; i++) {
      for (int j = 0; j < PARTS_HEALTH; j++) {
        healths[i][j].render(/*mvstack*/ heal, hurt, strengthen, weaken, resupply, energize, hallucinate, aps, dps, sps, light_ambients, light_diffuses, light_speculars, ambient_product, diffuse_product, specular_product, ambient_product2, diffuse_product2, specular_product2, enable, color_a_pink, emissive, Material_Emiss, shiny);
      }
    }
  }

  if (render_[SHIELDS]) {
    for (int i = 0; i < NUM_SHIELDS; i++) {
      for (int j = 0; j < PARTS_SHIELD; j++) {
        shields[i][j].render(/*mvstack*/ heal, hurt, strengthen, weaken, resupply, energize, hallucinate, aps, dps, sps, light_ambients, light_diffuses, light_speculars, ambient_product, diffuse_product, specular_product, ambient_product2, diffuse_product2, specular_product2, enable, color_a_pink, emissive, Material_Emiss, shiny);
      }
    }
  }

  if (render_[PLAYERS]) {
    for (int i = 0; i < NUM_PLAYERS; i++) {
      for (int j = 0; j < PARTS_PLAYER; j++) {
        players[i][j].render(/*mvstack*/ heal, hurt, strengthen, weaken, resupply, energize, hallucinate, aps, dps, sps, light_ambients, light_diffuses, light_speculars, ambient_product, diffuse_product, specular_product, ambient_product2, diffuse_product2, specular_product2, enable, color_a_pink, emissive, Material_Emiss, shiny);
      }
    }
  }

  if (render_[GHOSTS]) {
    for (int i = 0; i < NUM_GHOSTS; i++) {
      for (int j = 0; j < PARTS_GHOST; j++) {
        ghosts[i][j].render(/*mvstack*/ heal, hurt, strengthen, weaken, resupply, energize, hallucinate, aps, dps, sps, light_ambients, light_diffuses, light_speculars, ambient_product, diffuse_product, specular_product, ambient_product2, diffuse_product2, specular_product2, enable, color_a_pink, emissive, Material_Emiss, shiny);
      }
    }
  }

  if (render_[ZOMBIES]) {
    for (int i = 0; i < NUM_ZOMBIES; i++) {
      for (int j = 0; j < PARTS_ZOMBIE; j++) {
        zombies[i][j].render(/*mvstack*/ heal, hurt, strengthen, weaken, resupply, energize, hallucinate, aps, dps, sps, light_ambients, light_diffuses, light_speculars, ambient_product, diffuse_product, specular_product, ambient_product2, diffuse_product2, specular_product2, enable, color_a_pink, emissive, Material_Emiss, shiny);
      }
    }
  }

  if (render_[WEREWOLFS]) {
    for (int i = 0; i < NUM_WEREWOLFS; i++) {
      for (int j = 0; j < PARTS_WEREWOLF; j++) {
        werewolfs[i][j].render(/*mvstack*/ heal, hurt, strengthen, weaken, resupply, energize, hallucinate, aps, dps, sps, light_ambients, light_diffuses, light_speculars, ambient_product, diffuse_product, specular_product, ambient_product2, diffuse_product2, specular_product2, enable, color_a_pink, emissive, Material_Emiss, shiny);
      }
    }
  }

  if (render_[AGENCIES]) {
    for (int i = 0; i < NUM_AGENCIES; i++) {
      for (int j = 0; j < PARTS_AGENCIE; j++) {
        agencies[i][j].render(/*mvstack*/ heal, hurt, strengthen, weaken, resupply, energize, hallucinate, aps, dps, sps, light_ambients, light_diffuses, light_speculars, ambient_product, diffuse_product, specular_product, ambient_product2, diffuse_product2, specular_product2, enable, color_a_pink, emissive, Material_Emiss, shiny);
      }
    }
  }

}

#endif
