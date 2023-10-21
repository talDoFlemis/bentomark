#include "WarningDetector.h"

WarningDetector::WarningDetector(int maxIterations) {
    this->maxIterations = maxIterations;
}

bool WarningDetector::hasConverged(int currentIterations) const {
    return currentIterations > maxIterations;
}