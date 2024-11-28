#Oliver Lin
#1123511
#2024/11/28

import heapq  # 不需要用到 heapq，該模組可移除

def schedule_tasks_with_deadlines(n, tasks):
    """
    排程帶有截止時間的任務以最大化利潤。

    :param n: 任務數量
    :param tasks: 每個任務的資訊，以 (利潤, 截止時間) 的格式提供
    :return: (最大利潤, 排程後的任務利潤清單)
    """
    # 1. 按照任務的利潤從高到低排序
    tasks.sort(key=lambda x: x[0], reverse=True)
    
    # 2. 找到所有任務中最大的截止時間
    max_deadline = max(task[1] for task in tasks)
    
    # 3. 建立一個表示可用時槽的陣列，長度為最大截止時間 + 1 (因為截止時間是 1-based)
    slots = [False] * (max_deadline + 1)  # False 表示該時槽尚未被佔用
    scheduled_tasks = []  # 用來記錄已安排的任務利潤
    total_profit = 0  # 紀錄總利潤

    # 4. 遍歷每個任務，嘗試在其截止時間前找到可用時槽
    for profit, deadline in tasks:
        # 從該任務的截止時間開始，向前檢查是否有空時槽
        for slot in range(deadline, 0, -1):
            if not slots[slot]:  # 如果該時槽可用
                slots[slot] = True  # 標記該時槽為已佔用
                scheduled_tasks.append(profit)  # 將該任務利潤加入排程列表
                total_profit += profit  # 累加總利潤
                break  # 任務已排入，結束內層迴圈

    return total_profit, scheduled_tasks

# 主程式
if __name__ == "__main__":
    # 輸入任務數量
    n = int(input("Enter the number of tasks: "))
    
    # 輸入每個任務的利潤和截止時間
    print("Enter tasks in the format 'profit deadline' for each task:")
    tasks = [tuple(map(int, input().split())) for _ in range(n)]
    
    # 呼叫函數進行任務排程
    max_profit, scheduled_tasks = schedule_tasks_with_deadlines(n, tasks)
    
    # 輸出最大利潤和排程後的任務利潤
    print("Maximum Profit:", max_profit)
    print("Scheduled Tasks:", scheduled_tasks)
