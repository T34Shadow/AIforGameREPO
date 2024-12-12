#include "DisCondition.h"

bool DistanceCondition::IsTrue(Agent* agent)
{
    return (Vector2Distance(agent->GetPathAgent()->GetPos(), agent->GetPathAgent()->GetTarget()->GetPos()) < m_dis) == m_lessThan;
}
