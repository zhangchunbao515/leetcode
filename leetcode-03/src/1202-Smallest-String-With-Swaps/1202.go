var p []int

func smallestStringWithSwaps(s string, pairs [][]int) string {
    p = make([]int, len(s))
    for i := 0; i < len(s); i++ {
        p[i] = i
    }
    
    for _, v := range pairs {
        px, py := find(v[0]), find(v[1])
        if px != py {
            p[px] = py
        }
    }
    
    mem := make(map[int][]byte)
    for i := 0; i < len(p); i++ {
        x := find(p[i])
        mem[x] = append(mem[x], s[i])
    }
    for k, _ := range mem {
        sort.Sort(IntSlice(mem[k]))
    }
    
    res := make([]byte, 0)
    for i := 0; i < len(s); i++ {
        x := find(i)
        res = append(res, mem[x][0])
        mem[x] = mem[x][1:]
    }
    return string(res[:])
}

func find(x int) int {
    if x != p[x] {
        p[x] = find(p[x])
    }
    return p[x]
}

type IntSlice []byte

func (s IntSlice) Len() int {
    return len(s)
}

func (s IntSlice) Swap(i, j int) {
    s[i], s[j] = s[j], s[i]
}

func (s IntSlice) Less(i, j int) bool {
    return s[i] < s[j]
}