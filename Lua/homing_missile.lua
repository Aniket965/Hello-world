local util = dofile('Media/Scripts/internal/util.lua')

local homing_missile = {
  speed = 100,
  fireInterval = sf.seconds(5), 

  targetRule = function (proj, enemies) 
      local minDistance = floatMax()
      local closestEnemy

      for _, enemy in ipairs(enemies) do
        local enemyDistance = distance(enemy:getPosition(), proj:getPosition())

        if enemyDistance < minDistance then
          closestEnemy = enemy
          minDistance = enemyDistance
        end
      end
      
      return closestEnemy
    end,
  
  update = function (proj, dt) 
      if proj:hasTarget() and not proj:isDestroyed() then 
        local approachRate = 200
        local newVelocity
        newVelocity = unitVector(proj:getTargetDirection() * dt:asSeconds() * approachRate + proj:getVelocity())
        newVelocity = newVelocity * proj:getMaxSpeed()
        local angle = math.atan(newVelocity.y, newVelocity.x)
        proj:setRotation(toDegree(angle) + 90)
        proj:setVelocity(newVelocity) 
      end
    end,


  enemyCollider = function (proj, enemy) 
      enemy:damage(100)
      proj:destroy()
      proj:playAnimation('explode', false)
      proj:removeEmitters() 
      proj:setVelocity(sf.Vector2f.new(0, 0))
    end,

  graphics = {
    spritesheet = 'projectiles',
    textures = {
      {'main', 4, 134, 7, 41},
      {'display', 133 * 2, 0, 133, 133}
    },

    animations = {
      {
        spritesheet = 'explosion',
        id = 'explode',
        duration = sf.seconds(1),
        frames = {
          util.uniformFramesRect({0, 0, 256, 256}, 4, 4, true)
        }
      }
    },

    particles = {
      {
        system = 'smoke_system',
        emitters = {
          {
            emissionRate = 30,
            position = {0, math.floor(41 / 2)},
            particleColor = sf.Color.new(100, 100, 100),
            particleLifetime = {sf.seconds(1), sf.seconds(2)},
            particleVelocity = {0, 0, 0},
            index = 0
          }
        }
      },

      {
        system = 'fire_system',
        emitters = {
          {
            emissionRate = 30,
            position = {0, math.floor(41 / 2)},
            particleColor = sf.Color.new(240, 100, 0),
            particleLifetime = {sf.seconds(0.2), sf.seconds(0.8)},
            particleVelocity = {0, 0, 0},
            index = 0
          }
        }
      }
    }
  }

}


return homing_missile