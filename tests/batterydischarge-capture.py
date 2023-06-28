# Rad Pro
# Battery discharge capture
#
# (C) 2022-2023 Gissio
#
# License: MIT
#
# Notes:
# * To get the addresses for the 'battery and 'dose' variables,
#   compile the firmware and run these commands:
#
#   objdump -t platform.io/.pio/build/fs2011/firmware.elf | grep battery
#   objdump -t platform.io/.pio/build/fs2011/firmware.elf | grep dose
#

from datetime import datetime
import swd
import time

# Rad Pro variables
battery = 0x20000068
dose = 0x20000418

# Local variables
dev = None

battery_value = battery
doseTime = dose + 4

snapshot_last_time = None

file = open('batterydischarge-data.csv', 'a')

while True:
    # Get data
    if dev == None:
        dev = swd.Swd()

    try:
        snapshotTime = dev.get_mem32(doseTime)
        value = dev.get_mem32(battery_value)

        # Process data
        if snapshot_last_time != snapshotTime:
            snapshot_last_time = snapshotTime

            timestamp = datetime.now().strftime('%Y-%m-%dT%H:%M:%S.%f')
            file.write('"' + timestamp + '", ' + str(value) + '\n')
            file.flush()

        # Wait
        time.sleep(0.5)

    except Exception as e:
        print()
        print(e)

        dev = None

        time.sleep(5)