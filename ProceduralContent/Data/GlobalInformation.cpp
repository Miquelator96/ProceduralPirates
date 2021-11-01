// Fill out your copyright notice in the Description page of Project Settings.


#include "GlobalInformation.h"
#include "ProceduralContent/Weapons/WeaponComponent.h"
#include "ProceduralContent/Weapons/RangedWeapon.h"
#include "ProceduralContent/Weapons/MeleeWeapon.h"
#include "ProceduralContent/Characters/Pirate.h"

void UGlobalInformation::Init()
{
	SetupRangedWeapon("Pistol", 0.4f, 40, 0, 10, 15, 1);
	SetupMeleeWeapon("Sword", 0.7f, 50, 1, 1);
	SetupMeleeWeapon("Dagger", 0.8f, 20, 2, 0.6f);
	SetupRangedWeapon("Musket", 0.6f, 50, 3, 15, 30, 1);

	WeaponNames.Add("Pistol");
	WeaponNames.Add("Sword");
	WeaponNames.Add("Dagger");
	WeaponNames.Add("Musket");



}

void UGlobalInformation::SetupWeapon(FName _name, float _accuracy, int _damage, int _index)
{
	UWeaponComponent* aux = NewObject<UWeaponComponent>(this);
	aux->WeaponName = _name;
	aux->damage = _damage;
	aux->accuracy = _accuracy;
	aux->meshIndex = _index;

	WeaponsAvailable.Add(_name, aux);

}

void UGlobalInformation::SetupMeleeWeapon(FName _name, float _accuracy, int _damage, int _index, float _attackSpeed)
{
	UMeleeWeapon* aux = NewObject<UMeleeWeapon>(this);
	aux->WeaponName = _name;
	aux->damage = _damage;
	aux->accuracy = _accuracy;
	aux->meshIndex = _index;
	aux->attackSpeed = _attackSpeed;

	WeaponsAvailable.Add(_name, aux);

}

void UGlobalInformation::SetupRangedWeapon(FName _name, float _accuracy, int _damage, int _index, float _rechargeTime, int _range, int _ammunition)
{
	URangedWeapon* aux = NewObject<URangedWeapon>(this);
	aux->WeaponName = _name;
	aux->damage = _damage;
	aux->accuracy = _accuracy;
	aux->meshIndex = _index;
	aux->range = _range;
	aux->rechageTime = _rechargeTime;
	aux->ammunition = _ammunition;
	WeaponsAvailable.Add(_name, aux);

}
