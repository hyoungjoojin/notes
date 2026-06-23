+++
title = "machine-learning"
+++

# Machine Learning

## Supervised Learning

Supervised learning is the task of building a model that can learn from labeled
data to perform a specific task.

Formally, supervised learning can be defined as follows. Given a dataset with
input and output pairs $\lbrace (x_i, y_i) \rbrace_{i=1}^N$, a loss function
$l$, and a function class $\mathcal{G}$, the goal of supervised learning is to
find a function $g_{\theta} \in \mathcal{G}$ such that the expected loss over
the dataset $L(\theta) = \sum_{i=1}^N l(g_{\theta}(x_i), y_i)$ is minimized.

## Linear Regression

## Tabular Machine Learning

Tabular machine learning is the task of building a model that can use tabular
data to perform a specific task, such as making predictions, detecting
anomalies, clustering data, question answering, or synthetic data generation.

### Tabular Data

Tabular data is structured data that is organized into a two-dimensional table
of rows and columns.

Tabular data contains heterogeneous feature types, like numerical, categorical,
or free-form text features. Therefore, tabular models must handle the different
statistical properties of each feature type.

Within tabular data, it is very common to have missing values. Therefore,
tabular models must be robust to missing or unavailable features to handle
incomplete data.

Labels within tabular data are often noisy since they come from real-world data
sources. Also, certain features may be introduced after data leakage, for
example a feature can be measured after the target variable is observed. Models
must be robust to noisy labels and also should avoid features that are
introduced after leakage.

In tabular data, the order of the rows or columns are not important. Therefore,
the data does not contain any spatial or sequential structure, and tabular
models must be permutation-invariant across features.

Also, tabular data often have very small to medium dataset sizes. Since data is
very scarce, models must be data-efficient and robust to overfitting so that
models can generalize well from limited data.

Many tabular data are have highly imbalanced distributions. If the target
variable measures a rare event, a minority class may end up with a very small
number of samples. Models must avoid being biased towards the majority class,
and should detect rare events in the minority class. Also, evaluation of the
models should use appropriate metrics that can measure performance beyond simple
accuracy.

Tabular data are often domain-specific and therefore requires domain knowledge
to design effective features and models. General models must be able to adapt
across different domains, and models should learn the specific properties and
relationships from the data. Models should avoid making decisions purely based
on false correlations in the data by learning the underlying causal
relationships.

### Tabular Data Clustering

Common algorithms for aata clustering on tabular data include k-means, GMMs,
DBSCAN, and hierarchical clustering.

### Tabular Machine Learning Pipeline

Building machine learning models on top of tabular data works in the steps of
data collection, exploratory data analysis (EDA), data preprocessing, feature
engineering, modeling, evaluation, and deployment.

Data collection is the process of collecting relevant data from reliable
sources. Data can be collected from multiple tables, or from useful external
data sources. Reproducibility is important in the data collection process, so
that the same data can be collected again in the future.

EDA is the process of understanding the data through visualizations and
statistics. We can view information like summary statistics, missing value
patterns, distribution plots, correlation analysis, potential outliers, class
imbalance, and more to understand the data distribution and properties.

Data preprocessing is the process of transforming raw daat into a form that the
model can understand. Preprocessing should be done after the data is split into
training and test sets to avoid data leakage like using average values from the
test set.

Modeling is the process of selecting and training a machine learning model on
the preprocessed data. The models can range from simple linear models to
tree-based ensembles or deep neural networks using LLMs.

Evaluation is the process of measuring the performance of the model on a test
set. Metrics should be selected based on the specific task and data properties.
Cross-validation can be used for a more reliable assessment of the model's
performance.

Deployment is the process of putting the model into production. The deployed
model can be inferenced through either batch-based or real-time online
scenarios. Deployment should ensure consistency between training and deployment
environments, and the model's performance should be monitored over time to
detect any performance degradation or data drift.

#### Tabular Data Preprocessing

##### Handling Missing Values

We can use various techniques for handling missing values in tabular data.
Missing values can be removed entirely by removing the row, or be filled with a
constant value like an unknown category. They can also be imputed by statistical
measures like mean or median, or they can be imputed by complex model-based
techniques using other features. Some tree-based models or LLM-based approaches
can directly handle missing values.

##### Categorical Variable Encoding

Categorical variables can be encoded through various techniques. One-hot
encoding, ordinal encoding, target encoding, and embedding-based encoding are
common techniques for encoding categorical variables.

##### Numerical Feature Transformation

Numerical features can be transformed using various techniques in order to
prevent the model being sensitive to the scale of the features. Scaling
techniques like min-max scaling, standardization, and robust scaling can process
the feature to have a normalized form. Some models like tree-based models are
scale-invariant and do not require feature scaling. Scaled values may also be
less directly interpretable.

Distribution transformation techniques like log transformation or quantile
transformation can be used to transform skewed distributions into more normal
distributions. This can help the model learn better from the data.

Binning, or discretization techniques are used to convert continuous numerical
features into discrete bins. This can help capture non-linear relationships and
reduce the impact of outliers.

##### Feature Engineering

Feature engineering creates informative features from raw data using domain
knowledge and data-driven techniques. This can include creating interaction
features, polynomial features, or using dimensionality reduction techniques like
PCA to create new features.

#### Tabular Model Evaluation

A strong evaluation strategy is crucial for building a performant and robust
model.

Cross-validation and hyperparameter optimization is the process of improving the
model's performance by tuning the hyperparameters of the model using a
cross-validation strategy. Using a single validation set can lead to overfitting
on the validation set, and therefore cross-validation can provide a more
reliable estimate of the model's performance. Also, it is important that the
test set is strictly held out from the training and validation process.

Evaluation metrics should be selected based on the specific task and data
properties. Regression tasks can use metrics like MAE, MSE, or R-squared. Binary
classification tasks can use metrics like accuracy, precision, recall, or F1
scores.

If the metric should be threshold-independent, we can use metrics like AUC-ROC
or AUC-PR. AUC-PR is more informative than AUC-ROC for highly imbalanced data.

Evaluation metrics should reflect on what the goal of the task is. For example,
if the target has a very rare positive class, then PR-AUC or recall at fixed
precision can be used. If false positives are more costly than false negatives,
then precision can be prioritized. If false negatives are catastrophic, then
recall can be prioritized.

It is also useful to understand why a model made a specific prediction. This is
called model interpretability, and it answers questions like which features were
important for the model's prediction. Permutation importance is a technique
where we drop features and see how the model's performance changes to understand
which features are important for the model's prediction. SHAP values are a
technique that assigns an importance value to each feature for a specific
prediction.

## Natural Language Processing

### Tokenization

Tokenization is the process of converting raw text into a sequence of tokens.
The size of a token can vary from a single character to a word or subword.

#### Subword Tokenization

### Language Models

A language model is defined as the probability distribution over a sequence of
tokens. A token is defined as a unit of text within a finite vocabulary.

$$
p(x_{1:L}) = p(x_1, \cdots, x_L)
$$

Autoregressive language models are a type of language model that uses the chain
rule to factor the probability distribution over a sequence of tokens into a
product of conditional probabilities. This allows the model to predict the next
token based on the previous tokens in the sequence.

$$
p(x_{1:L}) = \prod_{i=1}^L p(x_i | x_{i-1})
$$

### Large Language Models (LLMs)

#### Decoding Algorithms

Decoding in language models is the process of selecting a token given the
model's output probability distribution.

##### Greedy Decoding

Greedy decoding is the simplest decoding algorithm, where we select the token
with the highest probability at each step. This can lead to suboptimal results
since it does not consider the overall sequence, therefore the greedy choice at
each step may not lead to the best overall sequence.

$$
x_{L+1} = \arg\max_{x} \hat{p}(x | x_{1:L})
$$

##### Beam Search

Beam search is a decoding algorithm that maintains a fixed number of candidate
sequences at each step, called the beam width. For example, if the beam width is
3, then at each step we take the top 3 highest probability tokens and expand
each of the candidate sequences with those tokens. This allows the algorithm to
consider multiple candidate sequences and can lead to better results than greedy
decoding. This does come with a computational cost since we need to maintain
multiple candidate sequences at each step.

###### Diverse Beam Search

Diverse beam search is a technique that modifies the beam search algorithm to
encourage diversity among the candidate sequences. This can be done by adding a
diversity penalty to the score of each candidate sequence based on how similar
it is to the other candidates. This can help prevent the model from generating
very similar sequences and can lead to more diverse outputs.

##### Sampling

Sampling is a decoding algorithm where we sample a token from the model's output
probability distribution at each step. This allows for more diversity in the
generated sequences, but it can also lead to less coherent results since we are
not always selecting the most probable token.

$$
x_{L+1} \sim \hat{p}(x | x_{1:L})
$$

To reduce the problem of incoherent results, we can use techniques like
temperature scaling. This is a technique where we control the randomness of the
sampling process by scaling the model's output probabilities with a temperature
parameter. A higher temperature will lead to more random samples, while a lower
temperature will lead to more deterministic samples.

$$
\hat{p}(x) = \text{softmax} ( \frac{\log p(x)}{T} )
$$

Top-K sampling is another technique where we only consider the top k most
probable tokens when sampling. Top-K sampling has the problem that the optimal
value of K can vary depending on the probability distribution of the model's
output.

Top-P sampling, or nucleus sampling, works on top of top-K sampling by selecting
K as the smallest number such that the cumulative probability of the top K
tokens is greater than or equal to a threshold P. This allows for more dynamic
selection of the number of tokens to consider when sampling, and can lead to
better results than top-K sampling.

##### Contrastive Decoding

Contrastive decoding is a decoding algorithm that aims to improve the quality of
generated probabilities by making the model less likely to generate mistakes.
This can be done by having an expert model and an amateur model, and have the
output probability be the difference between the two models' output
probabilities.

The expert model is trained to generate high-quality outputs, while the amateur
model is trained to generate low-quality outputs. By taking the difference
between the two models' output probabilities, we can encourage the model to
generate high-quality outputs and avoid mistakes.

An adaptive plausibility constraint is considered to ensure that not all tokens
are penalized equally.

We can guide the model's output by using a different amateur model depending on
the input's context or the task at hand. For example, contrastive decoding can
also be used in RAG systems to guide the model's output based on the retrieved
documents.

###### Context-Aware Contrastive Decoding

Context-aware contrastive decoding is a method of using contrastive decoding int
RAG contexts.

###### Visual Contrastive Decoding

##### Speculative Decoding

Speculative decoding is a decoding algorithm for improving the computational
efficiency of language models. The main idea is to use a smaller, faster model
to generate a draft sequence, and then use the larger, more powerful model to
only refine the draft sequence instead of generating the entire sequence from
scratch.

