#ifndef WARNINGDETECTOR_H
#define WARNINGDETECTOR_H

class WarningDetector{
    public:
        WarningDetector(int maxIterations);
        bool hasConverged(int currentIterations) const;
    private:
        int maxIterations;
};

#endif