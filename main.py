import fputs

if __name__ == '__main__':
    print(fputs.__doc__)
    print(fputs.FPUTS_FLAG)
    fputs.fputs("Real Python!", "write.txt")
    with open("write.txt", "r") as f:
        print(f.read())
