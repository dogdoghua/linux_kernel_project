# linux_kernel_project1
ncu csie Linux operation system final project:
kernel address space 都會對應到相同的 physical address。
  - kernel 如何實行此一特性?
  - 要設計程式來證明上面問題的答案


environment: ubuntu
## main idea:
  - 每個 process 都會 map virtual address 0xc0000000 之前的內容到各自的Page Global Directory(PGD)。
    相反的，每個 process 剩下的 entries should be the same to the corresponding entries of the Master Kernel Page Global Directory(MKPGD)
  - 所以只要證明不同 process 的MKPGD內容都一樣就可以了!! (都會指向process0的PGD)

## implementation
  - 寫一個system call: get_kernel_space() 用來印出某個process 的 PGD的後面768~1023項的內容
  - 寫一個C program ，建立出兩個不同的process，分別呼叫這個get_kernel_space()，看印出的內容是不是一樣的 

## result
![image](https://user-images.githubusercontent.com/79838009/132945255-77ffc75c-cf3e-4b9c-91d8-43c65b9120c4.png)
