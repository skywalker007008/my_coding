import os
import time
import signal
import subprocess
import sys

def monitor_forever_processes(process_name):
    while True:
        pids_to_monitor = {}
        
        for pid in os.listdir('/proc'):
            if pid.isdigit():
                try:
                    with open(f'/proc/{pid}/cmdline', 'rb') as cmdline_file:
                        cmdline = cmdline_file.read()
                        if process_name in cmdline.decode():
                            pids_to_monitor[pid] = cmdline.decode()
                except IOError:
                    continue

        for pid, cmdline in pids_to_monitor.items():
            print(f"Found '{process_name}' process with PID {pid}")

        for pid, cmdline in pids_to_monitor.items():
            if pid not in pids_to_monitor:
                continue
            
            # Check if the process is still alive
            try:
                os.kill(int(pid), 0)
            except ProcessLookupError:
                print(f"Process with PID {pid} is not running. Restarting...")
                subprocess.Popen([sys.executable, cmdline.split()[0], cmdline.split()[1]])

        time.sleep(1)

def main():
    if len(sys.argv) != 2:
        print("Usage: monitor.py <process_name>")
        sys.exit(1)

    process_name = sys.argv[1]

    try:
        monitor_forever_processes(process_name)
    except KeyboardInterrupt:
        print("Monitoring stopped.")

if __name__ == "__main__":
    main()