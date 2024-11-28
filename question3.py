#Oliver Lin
#1123511
#2024/11/28

import heapq  # 用於實現最小堆

def merge_k_sorted_arrays(k, arrays):
    """
    合併 k 個已排序的陣列，並返回一個排序後的陣列。

    :param k: 整數，表示陣列的數量
    :param arrays: 二維列表，每個子列表是一個已排序的陣列
    :return: 合併後的排序陣列
    """
    min_heap = []  # 最小堆，用於追蹤最小元素
    result = []    # 用於儲存合併後的結果

    # 步驟 1：將每個陣列的第一個元素放入最小堆中
    for i in range(k):
        if arrays[i]:  # 確保陣列非空
            # heappush 的格式為 (值, 陣列索引, 元素索引)
            heapq.heappush(min_heap, (arrays[i][0], i, 0))

    # 步驟 2：從最小堆中提取最小元素，並插入該元素所在陣列的下一個元素
    while min_heap:
        # 提取堆中的最小元素 (值, 所屬陣列索引, 元素索引)
        val, arr_idx, elem_idx = heapq.heappop(min_heap)
        result.append(val)  # 將最小值加入結果陣列

        # 如果該元素所在的陣列中還有剩餘元素，將下一個元素加入堆
        if elem_idx + 1 < len(arrays[arr_idx]):
            next_val = arrays[arr_idx][elem_idx + 1]
            heapq.heappush(min_heap, (next_val, arr_idx, elem_idx + 1))

    return result

# 主程式
if __name__ == "__main__":
    # 輸入 k (陣列數量)
    k = int(input("Enter the number of arrays: "))

    # 輸入每個已排序的陣列
    arrays = []
    for i in range(k):
        arr = list(map(int, input(f"Enter sorted array {i + 1}: ").split()))
        arrays.append(arr)

    # 呼叫函數合併陣列
    merged_array = merge_k_sorted_arrays(k, arrays)

    # 輸出結果
    print("Merged Array:", merged_array)
