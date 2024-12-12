#include "DisCondition.h"

bool DistanceCondition::IsTrue(Agent* agent)
{
    return (Vector2Distance(agent->GetPos(), agent->GetTarget()->GetPos()) < m_dis) == m_lessThan;
}
