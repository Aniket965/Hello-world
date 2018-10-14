using System;
using System.Collections.Generic;

namespace lab2
{
    class Program
    {
        static void Main(string[] args)
        {
            EnemyManager enemymanager = new EnemyManager();

            Enemy e1 = enemymanager.SpawnStrongerEnemy();
            Enemy e2 = enemymanager.SpawnStrongerEnemy();
            Enemy e3 = enemymanager.SpawnStrongerEnemy();
            Enemy e4 = enemymanager.SpawnStrongerEnemy();
        }
    }

    abstract class EnemyPrototype
    {
        public abstract EnemyPrototype Clone();
    }

    class Enemy : EnemyPrototype
    {
        private int power;

        public Enemy()
        {
            this.power = 0;
        }

        public override EnemyPrototype Clone()
        {
            EnemyPrototype clonedEnemy = this.MemberwiseClone() as EnemyPrototype;
            this.power++;
            Console.WriteLine(
              "Cloning enemy with power " + this.power);
            return clonedEnemy;
        }
    }

    class EnemyManager
    {
        private Enemy enemy = new Enemy();

        public Enemy SpawnStrongerEnemy()
        {
            return enemy.Clone() as Enemy;
        }
    }
}
