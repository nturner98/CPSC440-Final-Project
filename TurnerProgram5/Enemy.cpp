/*
Nick Turner
7/21/2020
CPSC 440J
Turner Program 5
*/
#include "Enemy.h"

#include <allegro5/allegro.h>
#include <allegro5\allegro_image.h>


Enemy::Enemy() {
	death = NULL;
	health = 1;	//temp setting
	live = false;
}

Enemy::~Enemy() {
	badGuy.~Sprite();
	al_destroy_sample(death);
}

void Enemy::init(int width, int height, int max_health, int fw, int fh, int max, int col, char* file_name, char* samp) {
	badGuy.InitEnemySprites(width, height, fw, fh, max, col, file_name, al_map_rgb(147, 187, 236));
	death = al_load_sample(samp);
	health = max_health;
}

void Enemy::hit() {
	health -= 1;
}

//FIXME
void Enemy::moveEnemy(int width, int height, int dir, int ani_dir) {
	
	//should move automatically towards Ness
	badGuy.UpdateSprites(width, height, 5, 5);	//TEMP

}

void Enemy::CollideHero(Player player, Sprite hero) {
	if (live)
	{
		int ex = badGuy.getX();	//enemy x
		int ebx = badGuy.getBoundX(); //enemy bound x
		int ey = badGuy.getY();
		int eby = badGuy.getBoundY();
		int hx = hero.getX();
		int hbx = hero.getBoundX();
		int hy = hero.getY();
		int hby = hero.getBoundY();
		
		/*if (ex - ebx < hx + hbx &&
			ex + ebx > hx - hbx &&
			ey - eby < hy + hby &&
			ey + eby > hy - hby)*/
		/*if ((ex < hbx || ebx < hbx)&&
			(ex > hx || ebx > hx) && 
			(ey < hby || eby < hby)&&
			(ey > hy || eby > hby)
			)*/
		if (((ex < hx && ebx > hx) || (ex > hbx && ebx < hbx)) &&
			((ey < hy && eby > hy) || (eby > hby && ey < hby)))
		{
			//TODO remove player life
			player.playOuch();
			Die();
		}
		
	}
}

void Enemy::Die() {
	
	live = false;
	al_play_sample(death, 1.0, 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
}

void Enemy::DrawSprites(int xoffset, int yoffset) {
	badGuy.DrawSprites(xoffset, yoffset);
}

bool Enemy::Collision() {
	return badGuy.CollisionEndBlock();
}
int Enemy::getX() {
	return badGuy.getX();
}
int Enemy::getY() {
	return badGuy.getY();
}
void Enemy::setX(int sx) {
	badGuy.setX(sx);
}
void Enemy::setY(int sy) {
	badGuy.setY(sy);
}
int Enemy::getWidth() {
	return badGuy.getWidth();
}
int Enemy::getHeight() {
	return badGuy.getHeight();
}

void Enemy::printDebug(int num) {
	printf("enemy #%i x and bx: %i, %i\n", num, badGuy.getX(), badGuy.getBoundX());
	printf("enemy #%i y and by: %i, %i\n", num, badGuy.getY(), badGuy.getBoundY());

}