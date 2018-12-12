definitely:

top right score hud representation
7 puzzles based on proximity to the player

4 enemy health instead of one shot
    gun base damage and and advantage and disadvantage values

8 mouse movement


fire mode switching
  // laser charge
  laser recharge
  rocket reload
  tracker reload
  tracker and rocket clip difference
  firemode and non damage difference

fix perspectives
  1st
    add guns
  2nd
    fix model

map some walls and doors
add secret buttons and passages for puzzles

gun firing timer
damage timer
pickups reload timer
laser charging and gun reloading timers

fix hud seg fault on shooting to many bullets
hud overhaul
  ortho fix
  hud models
  hud objects

add in accelaration
impulse would be accelaration over time
explosions?

2 TIME BASED SHIT!!!!!!
    anything that need it!!!!

8 added lighting - easy
9 sounds - medium
10 textures - hard
11 other ambiance creating effects

guns
  - uzi
    // + damage agency a lot
    // + damage zombie a little
    // + will not damage robot
    + will not damage ghost
  - RPGs
    // + damage agency alot
    // + damage zombie alot
    // + damage robot alot
    + will not damage ghost
  - laser
    // + damage agency alot
    // + damage zombie alot
    // + damage robot a little
    + damage ghost a little
  - vacuum
    + will only affect the ghost but it is a one hit kill

  - 2nd stage
    = implementation of the guns
      > types
        machine gun
          small bullets
          medium speed
          large bullet store
          fire modes
            // auto
            // semi-auto
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
            // discharge mode where the laser fires like a regular gun and recharges its ammo store
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
