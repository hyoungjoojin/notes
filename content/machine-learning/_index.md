+++
title = "machine-learning"
+++

# Machine Learning

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

