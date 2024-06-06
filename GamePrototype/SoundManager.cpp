#include "pch.h"
#include "SoundManager.h"

SoundManager::SoundManager() :
	m_pCouchingSound{ new SoundEffect("Player/sound/cough.mp3") },
	m_pBackgroundMusic{new SoundStream("Music/bgmusic.mp3")}
{

}


SoundManager::~SoundManager()
{
	delete m_pCouchingSound;
	delete m_pBackgroundMusic;
}


void SoundManager::Update(float elapsedSec)
{

}
void SoundManager::Draw() const
{

}

void SoundManager::PlayCoughingSound() const
{
	m_pCouchingSound->Play(0);
	m_pCouchingSound->SetVolume(15);
}

void SoundManager::PlayBackgroundSound() const
{
	m_pBackgroundMusic->Play(-1);
	m_pBackgroundMusic->SetVolume(15);
}
