# 42cursus-ft_printf

MAIN CHANGES:

- Changes on ft_atoi to work better with this project.
- Changes on ft_putchar so that ft_printf returns a global variable that gets incremented each time ft_putchar is called.
- Treatment of NULL on ft_putstr so that it printfs (null) instead of nothing.
- ft_strlen returns unsigned long long instead of size_t so that It could work with all cases of %p
- Protection of memory allocations whenever there is a malloc() and changes of the global variable g_error that was set as 0 to -1 in case of errors.
- I've written the code with the thought of having many files, so that each and every case gets treated by itself to make the code more readable.
- This code is absolutely free of segmentation faults or aborts... on the cases and flags treated. (-fsanitize=address) returns no memory problems now.
