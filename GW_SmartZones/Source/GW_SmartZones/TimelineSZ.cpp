
#include "TimelineSZ.h"
#include "Animation/AnimationAsset.h"

void UTimelineBehaviorSZ::Initialize( const FString& name, float timeStart, float timeEnd, UAnimationAsset* pAnim)
{
	m_Name = name;
	m_pAnimation = pAnim;
	m_TimeStart = timeStart;
	m_TimeEnd = timeEnd;
}

void UTimelineRowSZ::Initialize(const FString& name)
{
	m_Name = name;
}