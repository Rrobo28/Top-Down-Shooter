// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun.h"

AGun::AGun()
{
	BulletSpawn = CreateDefaultSubobject<USceneComponent>(TEXT("Bullet Spawn"));
	BulletSpawn->SetupAttachment(Mesh);
}
