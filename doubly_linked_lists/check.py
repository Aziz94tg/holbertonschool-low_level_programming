ok = "Zen of Python"
ok = ok + " C"
ok = ok[1:3] + ok[3] + ok[14] + ok[3] + ok[7:9] + ok[:6][::-1]

print(f"Expected password: '{ok}'")
entered = input("Password: ")

print(f"Entered password: '{entered}'")

if entered == ok:
    print("OK")
else:
    print("KO")
