from curses.ascii import isalnum
from os import remove
import sys # Used for reading in the command-line arguments
import ArgumentParser

def removeSymbols(rawText, symbolsToRemove, pos): # Recursively removes the unwanted symbols from the text input
  if (pos == len(symbolsToRemove)):
    return rawText
  scrubbedText = rawText.replace(symbolsToRemove[pos], ' ')
  return removeSymbols(scrubbedText, symbolsToRemove, pos + 1)

def processFileToList(inFile):
  rawText = inFile.read() # Reads in the entire file
  symbolsToRemove = list(set(filter(lambda character: not character.isalnum() and (character != '-' and character != ' ' and character != '.'), rawText))) # Filters out characters that aren't 0-9, a-z, a minus, space, or decimal
  scrubbedText = removeSymbols(rawText, symbolsToRemove, 0).split()
  return scrubbedText

def isInteger(hopefullyAnInt): # Tests to see if the passed argument is an integer
  try:
    tryForInt = int(hopefullyAnInt)
    return isinstance(tryForInt, int)
  except ValueError:
    return False

def isReal(hopefullyAReal): # Tests to see if the passed argument is a real number, or float
  try:
    if '.' in hopefullyAReal:
      tryForReal = float(hopefullyAReal)
      return isinstance(tryForReal, float)
    else:
      return False
  except ValueError:
    return False

def findIntegers(listOfContent):
  filteredIntegers = list(filter(lambda element: isInteger(element), listOfContent))
  return sorted(list(map(lambda intElement: intElement, filteredIntegers)), reverse=True) # Returns a descending sorted list created through map()

def findReals(listofContent):
  filteredReals = list(filter(lambda element: isReal(element), listOfContent))
  return sorted(list(map(lambda floatElement: floatElement, filteredReals)), reverse=True) # Returns a descending sorted list created through map()

def getSet(listOfNumbers):
  uniqueList = []
  list(filter(lambda num: uniqueList.append(num) if num not in uniqueList else None, listOfNumbers))
  return uniqueList

def countOccurrenceOf(targetNum, listOfNumbers):
  if not listOfNumbers: # Truth Value Testing: if the list is empty, it is considered False
    return 0
  if listOfNumbers[0] == targetNum:
    return 1 + countOccurrenceOf(targetNum, listOfNumbers[1:])
  else:
    return 0 + countOccurrenceOf(targetNum, listOfNumbers[1:])

def findFrequencies(listOfNumbers, setOfNumbers):
  return list(map(lambda number: (number, countOccurrenceOf(number, listOfNumbers)), setOfNumbers))

def sortPairsByFreq(listOfPairs):
  return sorted(listOfPairs, key=lambda element: element[1], reverse=True)
  # sorted() returns the sorted version of the list that it was passed, but it leaves the original list intact!

def reportResults(outFile, valueFreqsPairs, pos, k): # Recursive output to file.
  if (k == 0 or (k > 0 and len(valueFreqsPairs) == 0 )): # FIXME: Does not check if pos is within the bounds of the list!! Points was taken off for this.
    # outFile.write('\n')
    return
  outFile.write("{} {}\n".format(valueFreqsPairs[pos][0], valueFreqsPairs[pos][1]))
  reportResults(outFile, valueFreqsPairs, pos+1, k-1)


# ==================== Driving Code ==================== #
# Testing command: python freqnumber.py 'k=1;input=Test Cases/tc1.txt;output=freqnums.txt'
ArgumentParser.checkNumberOfArgs(sys.argv) # Performs a check on the amount of arguments given to the program.
COMMAND_ARGS = sys.argv[1]
K = int(ArgumentParser.get(COMMAND_ARGS, "k"))
INPUT = ArgumentParser.get(COMMAND_ARGS, "input")
OUTPUT = ArgumentParser.get(COMMAND_ARGS, "output")

# Opens the file and automatically closes it when it's finished
with open(INPUT, 'r') as inFile:
  listOfContent = processFileToList(inFile)

listOfInts = findIntegers(listOfContent)
listOfReals = findReals(listOfContent)

uniqueListOfInts = getSet(listOfInts)
uniqueListOfReals = getSet(listOfReals)

pairedIntFreqs = findFrequencies(listOfInts, uniqueListOfInts)
pairedRealFreqs = findFrequencies(listOfReals, uniqueListOfReals)

sortedIntFreqPairs = sortPairsByFreq(pairedIntFreqs)
sortedRealFreqPairs = sortPairsByFreq(pairedRealFreqs)

with open(OUTPUT, 'w') as outFile:
  outFile.write("integer:\n")
  reportResults(outFile, sortedIntFreqPairs, 0, K)
  outFile.write("real:\n")
  reportResults(outFile, sortedRealFreqPairs, 0, K)