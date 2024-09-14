while interval < N:
            for i in range(0, N - interval, interval * 2):
                lists[i] = merge2Lists(lists[i], lists[i + interval])
            interval *= 2