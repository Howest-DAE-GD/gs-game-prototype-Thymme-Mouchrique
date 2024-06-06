#pragma once
#include <SoundEffect.h>
#include <SoundStream.h>
class SoundManager
{
public:
	SoundManager();
	~SoundManager();

	void Update(float elapsedSec);
	void Draw() const;

	void PlayCoughingSound() const;
	void PlayBackgroundSound() const;
private:
	SoundEffect* m_pCouchingSound;
	SoundStream* m_pBackgroundMusic;

};

