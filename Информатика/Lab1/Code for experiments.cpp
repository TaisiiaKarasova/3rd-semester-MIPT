#include <iostream>
#include <set>
#include <random>
#include <fstream>

class State {

public:
    virtual bool contains(int s) const {
        return true;
    }
};

class DiscreteState: public State {
private:
    int const state;
public:
    DiscreteState(int state) : state(state) { }
   

    bool contains(int s) const {
        return s == state;
    }
};

class SegmentState: public State {
private:
    int const beg, end;

public:
    SegmentState() : beg(0), end(-1) { }
    SegmentState(int beg, int end) : beg(beg), end(end) { }

    bool contains(int s) const {
        return s >= beg && s <= end;
    }
};

class SetState : public State {
private:
    std::set<int> const states;

public:
    SetState() : states() { }
    SetState(std::set<int> const& src) : states(src) { }

    bool contains(int s) const {
        return states.count(s) > 0;
    }


    
};

class Segment_plus_Set : public State {
private:
    SegmentState segment;
    SetState set;

public:
    Segment_plus_Set(SegmentState segment, SetState set) : segment(segment), set(set) { }
    bool contains(int s) const {
        return segment.contains(s) || set.contains(s);
    }
};

class Segment_minus_Set : public State {
private:
    SegmentState segment;
    SetState set;

public:
    Segment_minus_Set(SegmentState segment, SetState set) : segment(segment), set(set) { }
    bool contains(int s) const {
        return segment.contains(s) && (~set.contains(s));
    }
};



class ProbabilityTest {
private:
    unsigned seed;
    int test_min, test_max;
    unsigned test_count;

public:
    ProbabilityTest(unsigned seed, int test_min, int test_max, unsigned test_count) : seed(seed), test_min(test_min), test_max(test_max), test_count(test_count) { }

    float operator()(State const& s) const {
        std::default_random_engine rng(seed);
        std::uniform_int_distribution<int> dstr(test_min, test_max);
        unsigned good = 0;
        for (unsigned cnt = 0; cnt != test_count; ++cnt)
            if (s.contains(dstr(rng))) ++good;

        return static_cast<float>(good) / static_cast<float>(test_count);
    }
};

int main(int argc, const char* argv[]) {
    DiscreteState d(3);
    SegmentState s(1, 20);
    SetState ss({ 1, 5, 7, 11, 16, 23, 28, 35, 41, 48, 52, 57, 60, 68, 73, 79, 87, 90, 95, 99});
    Segment_minus_Set s_m_ss(s, ss);
    Segment_plus_Set s_p_ss(s, ss);

    std::ofstream results_segment1("Segment1.txt");
    std::ofstream results_segment2("Segment2.txt");
    std::ofstream arguments_segment2("ArgSegment2.txt");

    std::ofstream results_set1("Set1.txt");
    std::ofstream results_set2("Set2.txt");
    std::ofstream arguments_set2("ArgSet2.txt");

    std::ofstream results_segment_plus_set1("Segment_plus_Set1.txt");
    std::ofstream results_segment_plus_set2("Segment_plus_Set2.txt");
    std::ofstream arguments_segment_plus_set2("ArgSegmentPSet2.txt");

    std::ofstream results_segment_minus_set1("Segment_minus_Set1.txt");
    std::ofstream results_segment_minus_set2("Segment_minus_Set2.txt");
    std::ofstream arguments_segment_minus_set2("ArgSegmentMSet2.txt");

    std::ofstream results_dicrete1("Discete1.txt");
    std::ofstream results_dicrete2("Discete2.txt");
    std::ofstream arguments_discrete2("ArgDiscrete2.txt");



    for (int j = 1; j <= 10000; j++)
    {
        ProbabilityTest pt(10, 0, 100, j);
        results_segment1 << pt(s) << std::endl;
    }

    for (int j = 1; j <= 10000; j++)
    {
        ProbabilityTest pt(10, 0, 100, j);
        results_set1 << pt(ss) << std::endl;
    }

    for (int j = 1; j <= 10000; j++)
    {
        ProbabilityTest pt(10, 0, 100, j);
        results_segment_minus_set1 << pt(s_m_ss) << std::endl;
    }

    for (int j = 1; j <= 10000; j++)
    {
        ProbabilityTest pt(10, 0, 100, j);
        results_segment_plus_set1 << pt(s_p_ss) << std::endl;
    }

    for (int j = 1; j <= 10000; j++)
    {
        ProbabilityTest pt(10, 0, 100, j);
        results_dicrete1 << pt(d) << std::endl;
    }

    for (int j = 200; j >= 20; j--)
    {
        ProbabilityTest pt(10, 0, j, 10000);
        results_segment2 << pt(s) << std::endl;
        arguments_segment2 << 20.0 / ((float) j) << std::endl;
    }

    for (int j = 200; j >= 20; j--)
    {
        ProbabilityTest pt(10, 0, j, 10000);
        results_set2 << pt(ss) << std::endl;
        arguments_set2 << 20.0 / ((float)j) << std::endl;
    }

    for (int j = 150; j >= 15; j--)
    {
        ProbabilityTest pt(10, 0, j, 10000);
        results_segment_minus_set2 << pt(s_m_ss) << std::endl;
        arguments_segment_minus_set2 << 15.0 / ((float)j) << std::endl;
    }

    for (int j = 350; j >= 35; j--)
    {
        ProbabilityTest pt(10, 0, j, 10000);
        results_segment_plus_set2 << pt(s_p_ss) << std::endl;
        arguments_segment_plus_set2 << 35.0 / ((float)j) << std::endl;
    }

    for (int j = 10; j >= 1; j--)
    {
        ProbabilityTest pt(10, 0, j, 10000);
        results_dicrete2 << pt(d) << std::endl;
        arguments_discrete2 << 1.0 / ((float)j) << std::endl;
    }

    return 0;
}
