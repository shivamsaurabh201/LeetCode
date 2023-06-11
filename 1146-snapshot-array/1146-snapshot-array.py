class SnapshotArray:
    def __init__(self, length):
        self.length = length
        self.data = [[(0, 0)] for _ in range(length)]
        self.snap_id = 0

    def set(self, index, val):
        self.data[index].append((self.snap_id, val))

    def snap(self):
        self.snap_id += 1
        return self.snap_id - 1

    def get(self, index, snap_id):
        snapshots = self.data[index]
        left, right = 0, len(snapshots) - 1

        while left <= right:
            mid = (left + right) // 2
            if snapshots[mid][0] <= snap_id:
                left = mid + 1
            else:
                right = mid - 1

        return snapshots[right][1]
