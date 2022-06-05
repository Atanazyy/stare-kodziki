import re
import sys
import io, base64, zipfile
from pathlib import Path

N = 10

def out_filename(i):
    return "output{:0>3}.txt".format(i)

def compress(strings):
    archive_buffer = io.BytesIO()
    with zipfile.ZipFile(archive_buffer, "w", zipfile.ZIP_DEFLATED) as archive:
        for i in range(len(strings)):
            archive.writestr(out_filename(i), strings[i])
    return base64.b64encode(archive_buffer.getvalue())

def decompress(data, n=N):
    archive_buffer = io.BytesIO(base64.b64decode(data))
    archive = zipfile.ZipFile(archive_buffer, "r")
    strings = []
    for i in range(n):
        strings.append(archive.open(out_filename(i)).read().decode())
    return strings

if __name__ == '__main__':
    assert len(sys.argv) == 2, "Przyjmuje jeden parametr: ścieżkę z outami"

    out_path = Path(sys.argv[1])

    codes = ["" for _ in range(N)]
    for path in out_path.glob("output*.txt"):
        numero = re.search("output0*(\d+).txt", str(path))[1]
        codes[int(numero)] = open(path).read().strip()

    assert codes == decompress(compress(codes)), "Sanity check"
    print("print('{}')".format(compress(codes).decode()))
