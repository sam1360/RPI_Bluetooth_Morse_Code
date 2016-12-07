import glob

def globprint(pattern):
    for file in glob.iglob(pattern, recursive=True):
        subslst = r"\subsubsection*{%s}" % file
        subslst = subslst.replace("_", r"\_")
        print(subslst)
        inputlst = r"\lstinputlisting{../%s}" % file
        inputlst = inputlst.replace("{", "{\"")
        inputlst = inputlst.replace("}", "\"}")
        print(inputlst)
        print("")

print("\subsection{Source Files}")
print("\n")
globprint('source/**/*.c')
print("\n")
print("\subsection{Include Files}")
print("\n")
globprint('include/**/*.h')
