①在矩形中取p个点作为初始解
②取一个足够大的步长delta
while (delta > epsilon)
{
    for (每个候选解)
    {
        for (i = 1 to L)
        {
            随机一个模长为delta，方向随机的向量加到点上作为新解
            试图用最优的合法新解替代原解
            Delta *= 0.8
            取目标函数值最大（距最近的陷阱距离最大）的解作为答案
        }
    }
}
