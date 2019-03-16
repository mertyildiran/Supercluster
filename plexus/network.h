#pragma once

#include <iostream>
#include <cstdlib>
#include <thread>

class Neuron;

enum NeuronType
{
    INTER_NEURON,
    SENSORY_NEURON,
    MOTOR_NEURON,
    NON_MOTOR_NEURON,
    NON_SENSORY_NEURON
};

class Network
{
    int precision;
    int connectivity;
    int connectivity_sqrt;

    std::vector<Neuron*> sensory_neurons;
    int input_dim;
    std::vector<Neuron*> motor_neurons;
    int output_dim;

    std::vector<Neuron*> nonsensory_neurons;
    std::vector<Neuron*> interneurons;
    bool randomly_fire;
    int motor_randomly_fire_rate;

    bool dynamic_output;
    double decay_factor;

    int initiated_neurons;

    int fire_counter;
    std::unordered_map<double, double> first_queue;
    std::unordered_map<double, double> next_queue;
    std::vector<double> output;
    int wave_counter;

    bool freezer;
    std::thread thread1;
    std::thread thread2;
    bool thread_kill_signal;

    void initiate_subscriptions();
    void pick_neurons_by_type(int output_dim, NeuronType neuron_type);
    void get_neurons_by_type(NeuronType neuron_type);
    static void _ignite();
    void ignite();

public:
    std::vector<Neuron*> neurons;
    std::vector<Neuron*> nonmotor_neurons;
    Network(int size, int input_dim, int output_dim, double connectivity, int precision, bool randomly_fire, bool dynamic_output, bool visualization, double decay_factor);
    int get_connectivity();
    int get_connectivity_sqrt();
    void increase_initiated_neurons();
};
