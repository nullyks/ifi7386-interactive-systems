# Diagnose an UNO R4 WiFi connection to the Pi

[Session 4](README.md) · [Pi setup](setup.md) · [Wi-Fi check sketch](examples/wifi_check/wifi_check.ino)

Use this page when Arduino cannot join the Pi hotspot, including when a phone can connect. Keep the working sensor sketch saved. This check needs only the UNO R4 WiFi and its USB cable; no sensor, RFID library, Node server or internet connection is needed.

## What is known, and what is not

During class both groups reported that their UNO R4 WiFi could not connect to a Pi 400 hotspot after a fresh OS installation. A phone could connect. This confirms that the hotspot was usable by at least one client; it does not identify why Arduino failed.

The original guide did not record the active security settings or require an Arduino-only connection checkpoint. Its application sketches printed no connection result, firmware version or IP address. They also measured the retry interval from BEFORE the blocking `WiFi.begin()` call, so a failed ten-second attempt could be followed immediately by another attempt. The revised sketches wait ten seconds after an attempt finishes. This is a confirmed code issue; it is not a confirmed explanation for the classroom failure.

The current classroom setup uses **Wi-Fi security: OPEN**, with no password. Both application sketches and the diagnostic sketch call `WiFi.begin(WIFI_NAME)`. Confirm that the active Pi hotspot is also OPEN; the change in configuration does not by itself prove what caused the earlier failure.

## 1. Check the actual Pi profile

Run these at the Pi keyboard or through Ethernet. Keep the hotspot running.

```bash
cat /etc/os-release
nmcli --version
nmcli -f NAME,UUID,TYPE,DEVICE connection show --active
nmcli connection show ifi-lab
iw dev wlan0 info
ip -4 address show dev wlan0
```

The profile name is `ifi-lab`; the broadcast network name (SSID) is `IFI7386-G1` or `IFI7386-G2`. If a different profile is active on wlan0, inspect that profile instead. If two profiles have the same name, use the active profile's UUID with `nmcli connection show uuid ACTUAL_UUID`.

The revised [setup commands](setup.md#hotspot-once-per-pi) explicitly set:

- AP mode, visible SSID, 2.4 GHz (`bg`), channel 6 or 11;
- OPEN security: no `802-11-wireless-security` setting and no Wi-Fi password;
- IPv4 `shared`, Pi address `10.42.0.1/24`.

Apply the OPEN conversion commands in [Pi setup](setup.md#convert-an-existing-password-protected-hotspot-to-open) to an existing password-protected profile. They remove the entire wireless-security setting, including the old password and WPA configuration. Deactivate/reactivate the profile so saved changes take effect. That briefly disconnects Wi-Fi clients.

## 2. Run the Arduino-only check

1. Open [examples/wifi_check/wifi_check.ino](examples/wifi_check/wifi_check.ino) in Arduino IDE. Select **Arduino UNO R4 WiFi** and the USB port.
2. Set `WIFI_NAME` to the ACTIVE Pi hotspot. For Group 2, change it to `IFI7386-G2`. Spelling and letter case matter. There is no password variable; the network must be OPEN.
3. Upload. Open Serial Monitor at **115200**, then press the Arduino **Reset** button to capture the startup messages.
4. Save the firmware version, target SSID, scan result (including channel/security), `WiFi.begin result`, current status and Arduino IP address.

The sketch scans once and makes ONE connection attempt with a twenty-second timeout. It then prints the current status every five seconds, so a late connection is visible. Press Reset to scan and try again. The target SSID should be labelled `OPEN` in the scan. `TARGET_NOT_OPEN` means the library reports security on that SSID; convert the active Pi profile to OPEN before retrying.

| Evidence | Meaning and next step |
|---|---|
| `WIFI_NO_MODULE` or `SCAN_FAILED` | Investigate communication with the connectivity module and its firmware |
| `TARGET_NOT_SEEN` | Arduino did not see the configured SSID in that scan; check active SSID, 2.4 GHz, channel, signal and antenna placement |
| `TARGET_NOT_OPEN` | The target SSID is secured; convert its active profile to OPEN and restart the hotspot |
| `TARGET_SEEN` with `OPEN`, then `WL_CONNECT_FAILED` | The SSID is visible but the open-network attempt failed; collect the Pi log to distinguish association and address-allocation problems |
| `WL_CONNECTED` and `Arduino IP: 0.0.0.0` | No usable IPv4 address yet; inspect DHCP/address assignment and repeat the status check |
| `WIFI_IP_OK` and an address such as `10.42.0.23` | Wi-Fi and IPv4 worked at that moment; proceed to the server checkpoint |
| Valid IP, followed by application `HOST_UNREACHABLE` | Inspect the destination address, port, running Node server and firewall |

`10.42.0.1` belongs to the Pi. Arduino should receive its own different address. Do not assign the Pi's address to Arduino. Port 3000/3001 affects reaching the application after connection; it does not control joining the hotspot.

## 3. Capture the Pi side during an attempt

In a Pi terminal, start this and then press Reset on Arduino:

```bash
sudo journalctl -f -u NetworkManager
```

Stop following with Ctrl+C after one attempt. Save the recent logs and connected-station information:

```bash
sudo journalctl -b -u NetworkManager --since "-5 min" --no-pager
sudo journalctl -b -u wpa_supplicant --since "-5 min" --no-pager
sudo iw dev wlan0 station dump
```

A station entry is evidence of a radio connection, not proof that DHCP completed. If the phone is still connected, its entry can appear too; compare the MAC address printed by the Arduino check. Look for association/authentication failures and DHCP activity around the attempt. Default logs may not include all details; absence of a line does not prove a step succeeded or failed.

Keep the OS release, NetworkManager version, profile output, Arduino output and timestamped Pi log together. The current OPEN setup has no Wi-Fi password.

## 4. Compare another access point, then firmware

As a separate test, use another **2.4 GHz OPEN access point**, such as a phone hotspot if it allows an OPEN network. Put its actual SSID in `WIFI_NAME` in the diagnostic sketch and upload it again. If the phone requires a password, skip that phone comparison or use another OPEN access point; the supplied sketch is configured for OPEN Wi-Fi.

- Arduino joins the phone hotspot but not the Pi: focus on the Pi/Arduino combination, active Pi profile and connection logs. This does not yet identify a particular setting.
- Arduino cannot join either OPEN network: investigate its connectivity firmware, board package, SSID, power and signal before changing the Pi OS.

For firmware, use Arduino IDE **Tools → Firmware Updater**, select UNO R4 WiFi, check updates and install the offered current firmware. **Then disconnect and reconnect USB before uploading the diagnostic sketch again.** The updater overwrites the sketch; saving your source first lets you restore it. Updating the Arduino board package or reinstalling Raspberry Pi OS does not itself update the board's connectivity firmware.

## 5. Return to the complete example

Restore your group's network sketch and actual Wi-Fi settings. The revised examples print the firmware version and target SSID at startup, the connection result after each attempt, and `WIFI_CONNECTED` with an IP address after joining.

First confirm a usable Arduino IP, then start the group's Pi server and look for HTTP 200, and finally check the browser. Keep these three checkpoints separate. Repeat with both real boards before class; a successful phone test alone is insufficient.

## Sources

- [NetworkManager hotspot command](https://networkmanager.pages.freedesktop.org/NetworkManager/NetworkManager/nmcli.html): profile creation, activation and inspection.
- [NetworkManager Wi-Fi security settings](https://www.networkmanager.dev/docs/api/latest/settings-802-11-wireless-security.html): security-profile properties; the OPEN setup omits the wireless-security setting entirely.
- [WiFiS3 1.5.3 implementation](https://github.com/arduino/ArduinoCore-renesas/blob/1.5.3/libraries/WiFiS3/src/WiFi.cpp): the default ten-second wait inside `begin()` and generic failure result.
- [Arduino connectivity firmware update instructions](https://support.arduino.cc/hc/en-us/articles/9670986058780-Update-the-connectivity-module-firmware-on-UNO-R4-WiFi): Firmware Updater and reconnecting USB before the next upload.
