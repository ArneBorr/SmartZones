#pragma once

#include "CoreMinimal.h"
#include <functional>

class ConditionBase
{
public: 
	virtual ~ConditionBase() {};
	virtual bool Call() { return false; };
};

template< typename... args>
struct ConditionFunction
{
	explicit ConditionFunction(std::function<bool(args...)> f, args... ar) :
		Function(f), Arguments(std::tuple<args...>(ar...)) {}

	std::function<bool(args...)> Function;
	std::tuple<args...> Arguments;
};

template< typename... args>
class Condition final : public ConditionBase, public ConditionFunction<bool, args...>
{
	bool Call() override
	{
		return Function(std::get< std::index_sequence_for<args...>() >(tuple)...);
	}
};

class GW_SMARTZONES_API ConditionRepository
{
public:
	ConditionRepository();
	~ConditionRepository();

	void AddCondition() 
	{
	};

	TArray<ConditionBase*> m_pConditions;
};
