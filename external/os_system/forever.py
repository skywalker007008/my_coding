import sys
import os
import subprocess

def main():
    if len(sys.argv) != 2:
        print("Usage: forever.py <argument>")
        sys.exit(1)

    argument = sys.argv[1]

    proc = subprocess.Popen(['ping', 'www.google.com'])



    # # Start a new process and run it indefinitely in the background
    # pid = os.

    # if pid == 0:  # This is the child process
    #     while True:
    #         print(f"pid_{os.getpid()} forever {argument}")
    #         # Add some sleep to prevent high CPU usage
    #         subprocess.Popen(["sleep", "1"]).wait()
    # else:
    #     # This is the parent process
    #     print(f"Started a new process with pid_{pid}")

if __name__ == "__main__":
    main()