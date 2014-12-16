BASE=readfile

all: \
	$(BASE).o \
	$(BASE).pdf \
	$(BASE).copie.pdf \
	$(BASE).patch \
	$(BASE).patch.pdf \
	$(BASE).sp.o \
	$(BASE).sp.pdf \
	$(BASE).algo.pdf \

%.o: %.cc
	g++ -Wall -Wpedantic -o $@ $<

$(BASE).patch: $(BASE).cc $(BASE).copie.cc
	@diff -uBb $(BASE).copie.cc $(BASE).cc > $@

%.ps: %.txt
	iconv -f utf8 -t iso8859-1 $< > $<.tmp
	a2ps -g -B -1 --tabsize=2 --chars-per-line=80 -B --line-numbers=1 -o $@ $<.tmp
	rm $<.tmp

%.patch.ps: %.patch
	iconv -f utf8 -t iso8859-1 $< > $<.tmp
	a2ps -g -B -1 --tabsize=4 --chars-per-line=80 -B --line-numbers=1 -o $@ $<.tmp
	rm $<.tmp

%.ps: %.cc
	iconv -f utf8 -t iso8859-1 $< > $<.tmp
	a2ps -g -B -1 --tabsize=4 --chars-per-line=80 -B --line-numbers=1 -o $@ $<.tmp
	rm $<.tmp

%.pdf: %.ps
	ps2pdfwr $<

clean:
	rm -f *.ps *.pdf *.o
