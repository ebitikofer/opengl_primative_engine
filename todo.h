definitely:
6 fire mode switching

3 score hud representation && ortho fix for the HUD
7 puzzles based on proximity to the player

2 TIME BASED SHIT!!!!!!
    laser charging and gun reloading
    pickups reload
    accelaration and impulses
      explosions
    anything that need it!!!!
4 enemy health instead of one shot
    gun base damage and and advantage and disadvantage values

5 object physics
    enemy physics
8 mouse movement




8 added lighting - easy
9 sounds - medium
10 textures - hard
11 other ambiance creating effects

player
  perspective
    1st person
      camera
    3rd person
      camera plus model
  supplies
    health
    shield
    ammos
  equipment
    items
    weapons

environment
  puzzles based on proximity to the player

guns
  - uzi
    + damage agency a lot
    + damage zombie a little
    + will not damage robot
    + will not damage ghost
  - RPGs
    + damage agency alot
    + damage zombie alot
    + damage robot alot
    + will not damage ghost
  - laser
    + damage agency alot
    + damage zombie alot
    + damage robot a little
    + damage ghost a little
  - vacuum
    + will only affect the ghost but it is a one hit kill

Incremental development plan:

  - 1st stage
    = develop the environment
      > including basic physics
        // ~ position
        ~ velocity
        ~ acceleration
        ~ impulse?
        ~ gravity, explosions, damage kick back, and jumping/movement
      > collision and proximity detection
      > enemies
        All of the enemies will incorporate a basic AI to track the player in their respective proximities.
        ~ human
          # pursue quickly & far
        ~ zombie
          # pursue quickly & close
        ~ ghost
          # pursue slowly & close
        ~ robot
          # pursue slowly & far
      > the actual physical environment
        ~ the walls
        ~ floors
        ~ pickups
          # resupplies
            + heath
            + armor
            + bullets
            + rockets
        ~ characters.

  - 2nd stage
    = implementation of the guns
      > types
        machine gun
          small bullets
          medium speed
          large bullet store
          fire modes
            auto
            semi-auto
        rocket launcher
          large bullets
          slow speed
          small bullet store
          fire mode
            non-tracking projectile with a larger explosion
            tracking projectile with a smaller explosion
        laser
          medium amount of damage
          tiny bullets
          fast speed
          infinite ammo
          fire modes
            discharge mode where the laser fires like a regular gun and recharges its ammo store
            charge mode where the player charges the laser and it releases a burst of energy when fired
        vacuum
          no damage
          no bullets
          no speed
          infinite ammo
          fire modes
            suck
      > behaviors
      > effects on the respective enemies
    = modified enemy behavior
    = enemy effects on players supplies
      > agency
        ~ shield 1st & quickly
        ~ health 2nd & slowly
      > zombie
        ~ shield 1st & slowly
        ~ health 2nd & quickly
      > robot
        ~ shield 1st & average
        ~ health 2nd & average
        ~ takes current ammo
      > ghost
        ~ skip shield
        ~ health 1st & average speed
    = HUD to represent player equipment and supplies
      > score
      > current weapons
      > current pickup

  - 3rd stage
    = added lighting
    = textures
    = sounds
    = other ambiance creating effects
